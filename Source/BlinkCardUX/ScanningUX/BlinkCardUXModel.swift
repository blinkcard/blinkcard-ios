//
//  BlinkCardUXModel.swift
//  BlinkCardUX
//
//  Created by Toni Kreso on 17.12.2025..
//

import AVFoundation
import Foundation
import CoreImage
import Combine
import SwiftUI

import BlinkCard

/// A view model that manages the user experience flow for document scanning.
/// Handles camera preview, document detection, user guidance, and scanning state transitions.
@MainActor
public final class BlinkCardUXModel: ScanningViewModel<BlinkCardScanningResult, BlinkCardUIEvent, BlinkCardReticleStateMachine, BlinkCardScanningAlertType> {
    /// The result of the document verification capture process.
    /// Contains the captured document images and associated data.
    @Published public var result: BlinkCardResultState?
    
    private var cancellables = Set<AnyCancellable>()
    
    public init(analyzer: any CameraFrameAnalyzer<CameraFrame, BlinkCardUIEvent>, uxSettings: ScanningUXSettings = ScanningUXSettings()) {
        super.init(analyzer: analyzer, uxSettings: uxSettings, reticleStateMachine: BlinkCardReticleStateMachine(), firstSideFinishedText: "mb_accessibility_success_card_number_side_scanned".localizedString, scanFinishedText: "mb_accessibility_success_card_scanned".localizedString)
        
        startEventHandling()
        camera.$status
            .sink { [weak self] _ in
                self?.objectWillChange.send()
            }
            .store(in: &cancellables)
    }
    
    // MARK: - Protocol Implementation
    public override func processAnalyzerResult() async {
        let result = await analyzer.result()
        if let scanningResult = result as? ScanningResult<BlinkCardScanningResult, BlinkCardScanningAlertType> {
            switch scanningResult {
            case .completed(let scanningResult):
                await finishScan()
                self.result = BlinkCardResultState(scanningResult: scanningResult)
            case .interrupted(let alertType):
                self.alertType = alertType
            case .cancelled:
                showLicenseErrorAlert = true
            case .ended:
                self.result = BlinkCardResultState(scanningResult: nil)
            }
        }
    }
    
    // - MARK: - Handle UIEvents
    private func startEventHandling() {
        eventHandlingTask = Task {
            for await events in await analyzer.events.stream {
                if events.contains(.requestSecondSide) {
                    firstSideScanned(frontFlipImage: Image.frontCardImage, backFlipImage: Image.backCardImage, flipState: .flip, nextState: .second)
                    cancelTooltipTimer()
                } else if events.contains(.fieldIdentificationFailed) {
                    self.setReticleState(.error("mb_blinkcard_card_not_fully_visible"))
                    self.trackErrorMessage(.keepvisible)
                } else if events.contains(.wrongSide) {
                    self.setReticleState(.error("mb_blinkcard_scanning_wrong_side"))
                    self.trackErrorMessage(.flipside)
                } else if events.contains(.imageReturnFailed) {
                    self.setReticleState(.error("mb_blinkcard_card_not_fully_visible"))
                    self.trackErrorMessage(.keepvisible)
                } else if events.contains(.tooClose) {
                    self.setReticleState(.error("mb_move_farther"))
                    self.trackErrorMessage(.movefarther)
                } else if events.contains(.tooFar) {
                    self.setReticleState(.error("mb_move_closer"))
                    self.trackErrorMessage(.movecloser)
                } else if events.contains(.tilt) {
                    self.setReticleState(.error("mb_blinkcard_keep_card_parallel"))
                    self.trackErrorMessage(.aligndocument)
                } else if events.contains(.tooCloseToEdge) {
                    self.setReticleState(.error("mb_move_farther"))
                    self.trackErrorMessage(.movefromedge)
                } else if events.contains(.notFullyVisible) {
                    self.setReticleState(.error("mb_blinkcard_card_not_fully_visible"))
                    self.trackErrorMessage(.keepvisible)
                } else if events.contains(.blur) {
                    self.setReticleState(.error("mb_blinkcard_blur_detected"))
                    self.trackErrorMessage(.eliminateblur)
                } else {
                    self.setReticleState(reticleStateMachine.fallbackState)
                }
            }
        }
    }
}
