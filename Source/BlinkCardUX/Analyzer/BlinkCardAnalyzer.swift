//  Created by Toni Kreso on 17.12.2025..
//  Copyright (c) Microblink. All rights reserved.
//  This code is provided for use as-is and may not
//  be copied, modified, or redistributed.
//

import Foundation
import AVFoundation
import CoreVideo

import BlinkCard

public actor BlinkCardEventStream: EventStream {
    private let events: AsyncStream<[BlinkCardUIEvent]>
    private let continuation: AsyncStream<[BlinkCardUIEvent]>.Continuation
    
    public init() {
        var continuation: AsyncStream<[BlinkCardUIEvent]>.Continuation!
        self.events = AsyncStream { continuation = $0 }
        self.continuation = continuation
    }
    
    deinit {
        self.continuation.finish()
    }
    
    /// Sends UI events to the stream.
    /// - Parameter events: Array of UI events to be processed
    public func send(_ events: [BlinkCardUIEvent]) {
        continuation.yield(events)
    }
    
    /// The underlying async stream of UI events.
    public var stream: AsyncStream<[BlinkCardUIEvent]> {
        events
    }
}

public actor BlinkCardAnalyzer: CameraFrameAnalyzer {
    
    public typealias Event = BlinkCardUIEvent
    
    public typealias Result = ScanningResult<BlinkCardScanningResult, BlinkCardScanningAlertType>
    public typealias Frame = CameraFrame
    
    private let session: BlinkCardSession
    private let eventStream: BlinkCardEventStream
    private let translator: BlinkCardUXTranslator = BlinkCardUXTranslator()
    private var scanningDone = false
    private var paused = false
    private var resultContinuation: CheckedContinuation<Result, Never>?
    public private(set) var stepTimeoutDuration: TimeInterval
    private var timerTask: Task<Void, Never>?
    
    /// Creates a new document verification analyzer.
    /// - Parameters:
    ///   - sdk: The document verification SDK instance
    ///   - captureSessionSettings: Settings for the capture session
    ///   - eventStream: Stream to receive UI events during scanning
    ///   - classFilter: Class filter to filter document classes based on country, region, and document type
    public init(
        sdk: BlinkCardSdk,
        blinkCardSessionSettings: BlinkCardSessionSettings = BlinkCardSessionSettings(inputImageSource: .video),
        eventStream: BlinkCardEventStream
    ) async throws {
        self.session = try await sdk.createScanningSession(sessionSettings: blinkCardSessionSettings)
        self._sessionNumber = await session.getSessionNumber()
        self.eventStream = eventStream
        self.stepTimeoutDuration = blinkCardSessionSettings.stepTimeoutDuration
    }
    
    private let _sessionNumber: Int
        
    nonisolated public var sessionNumber: Int {
        return _sessionNumber
    }
        
    /// Processes a camera frame for document analysis.
    /// - Parameter image: The camera frame to analyze
    public func analyze(image: Frame) async {
        guard !paused else { return }
        
        if timerTask == nil {
            startTimer(stepTimeoutDuration)
        }
        
        let inputImage = InputImage(cameraFrame: image)
        
        do {
            let frameProcessResult = try await session.process(inputImage: inputImage)
            
            let events = translator.translate(frameProcessResult: frameProcessResult, scanningSettings: session.settings.scanningSettings)
            
            await eventStream.send(events)
            
            if frameProcessResult.processResult?.resultCompleteness.scanningStatus == .cardScanned {
                guard !scanningDone else { return }
                scanningDone = true
                Task { @ProcessingActor in
                    let sessionResult = session.getResult()
                    await finishScanning(with: .completed(sessionResult))
                }
            }
        } catch {
            resultContinuation?.resume(returning: .cancelled)
        }
    }
    
    private func finishScanning(with result: ScanningResult<BlinkCardScanningResult, BlinkCardScanningAlertType>) {
        timerTask?.cancel()
        resultContinuation?.resume(returning: result)
        resultContinuation = nil
    }
    
    /// Cancels the current document scanning session.
    public func cancel() {
        self.session.cancelActiveProcessing()
    }
    
    /// Returns the final result of the scanning session.
    public func result() async -> ScanningResult<BlinkCardScanningResult, BlinkCardScanningAlertType> {
        await withCheckedContinuation { continuation in
            self.resultContinuation = continuation
        }
    }
    
    /// Pauses the document analysis.
    public func pause() {
        self.paused = true
        self.cancel()
        timerTask?.cancel()
    }
    
    /// Resumes the document analysis after being paused.
    public func resume() {
        guard paused else { return }
        self.session.resumeActiveProcessing()
        
        paused = false
        startTimer(stepTimeoutDuration)
    }
    
    /// Restarts the document analysis after being paused.
    public func restart() throws {
        Task { @ProcessingActor in
            try self.session.reset()
        }
        translator.resetState()
        resume()
    }
    
    public func end() {
        pause()
        resultContinuation?.resume(returning: .ended)
        resultContinuation = nil
    }
    
    /// Stream of UI events generated during document analysis.
    nonisolated public var events: any EventStream<BlinkCardUIEvent> {
        eventStream
    }
    
    private func startTimer(_ interval: TimeInterval) {
        guard interval > 0.0 else { return }
        timerTask = Task() { [weak self] in
            while !Task.isCancelled {
                guard let self else { return }
                let nanoseconds = UInt64(interval * Double(NSEC_PER_SEC))
                try? await Task.sleep(nanoseconds: nanoseconds)
                if !Task.isCancelled {
                    await scanInterrupted(with: .timeout)
                }
            }
        }
    }
    
    private func scanInterrupted(with alertType: BlinkCardScanningAlertType) {
        pause()
        resultContinuation?.resume(returning: .interrupted(alertType))
        resultContinuation = nil
        
        // ADR 15 - Platform implemented scan timeout
        Task {
            await PingManager.shared.sendPinglets()
        }
    }
}
