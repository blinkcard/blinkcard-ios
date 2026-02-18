//  BlinkCardUXView.swift
//  BlinkCardUX
//  This code is provided for use as-is and may not be copied, modified, or redistributed.
//

import SwiftUI

import BlinkCard

/// Main scanning view.
/// This view consists of `CameraView` and `Reticle`.
///
/// For `UIEvent` stream, and UX logic, see ``ScanningUXModel``.
public struct BlinkCardUXView: View, ScanningUXProtocol {
    typealias GenericContentView = AnyView
    typealias ScanResult = BlinkCardScanningResult
    typealias AlertType = BlinkCardScanningAlertType
    typealias UXModel = BlinkCardUXModel
    typealias EventType = BlinkCardUIEvent
    typealias ReticleStateMachineType = BlinkCardReticleStateMachine
    typealias OnboardingStepType = BlinkCardOnboardingStep
    
    @ObservedObject var viewModel: BlinkCardUXModel
    
    let theme = BlinkCardTheme.shared
    
    public init(viewModel: BlinkCardUXModel) {
        self.viewModel = viewModel
    }
    
    public var body: some View {
        MainView(reticleStateMachine: viewModel.reticleStateMachine, isTorchOn: $viewModel.isTorchOn, showToast: $viewModel.isToastVisible, showSheet: $viewModel.showSheet, showLicenseErrorAlert: $viewModel.showLicenseErrorAlert, onboardingAlertTitle: "mb_blinkcard_onboarding_dialog_title", onboardingAlertDescription: "mb_blinkcard_onboarding_dialog_message", onboardingAlertImage: Image.scanNumberFirstImage, timeoutAlertDescription: "mb_blinkcard_recognition_timeout_dialog_message".localizedString, flashlightWarningMessage: "mb_blinkcard_flashlight_warning_message".localizedString)
    }
}
