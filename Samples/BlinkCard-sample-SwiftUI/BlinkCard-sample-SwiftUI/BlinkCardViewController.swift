// Created by Jura Skrlec on 17.02.2021..
// Copyright (c) 2021 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

import Foundation
import SwiftUI
import BlinkCard

struct BlinkCardViewController: UIViewControllerRepresentable {
    @Environment(\.presentationMode) var presentationMode
    @Binding var showAlert: Bool
    @Binding var blinkCardRecognizer: MBCBlinkCardRecognizer
    class Coordinator: NSObject, MBCBlinkCardOverlayViewControllerDelegate {
        
        var parent: BlinkCardViewController
        
        init(_ parent: BlinkCardViewController) {
            self.parent = parent
        }
        
        func blinkCardOverlayViewControllerDidFinishScanning(_ blinkCardOverlayViewController: MBCBlinkCardOverlayViewController, state: MBCRecognizerResultState) {
            blinkCardOverlayViewController.recognizerRunnerViewController?.pauseScanning()
            
            if state == .valid {
                parent.showAlert = true
            }
        }
        
        func blinkCardOverlayViewControllerDidTapClose(_ blinkCardOverlayViewController: MBCBlinkCardOverlayViewController) {
            parent.presentationMode.wrappedValue.dismiss()
        }
        
        func blinkCardOverlayViewControllerDidFinishEditing(_ blinkCardOverlayViewController: MBCBlinkCardOverlayViewController, editResult: MBCBlinkCardEditResult) {
            
            /** Needs to be called on main thread beacuse everything prior is on background thread */
            DispatchQueue.main.async {
                // present the alert view with scanned results
                
                let alertController: UIAlertController = UIAlertController.init(title: "BlinkCard Edit Results", message: editResult.description, preferredStyle: .alert)
                
                let okAction: UIAlertAction = UIAlertAction.init(title: "OK", style: .default,
                                                                 handler: { (action) -> Void in
                                                                    self.parent.presentationMode.wrappedValue.dismiss()
                })
                alertController.addAction(okAction)
                blinkCardOverlayViewController.blinkCardEditViewController?.present(alertController, animated: true, completion: nil)
            }
        }
    }
    
    func makeCoordinator() -> Coordinator {
        Coordinator(self)
    }
    
    func makeUIViewController(context: Context) -> some UIViewController {
        blinkCardRecognizer.extractIban = false
        

        /** Create settings */
        let settings = MBCBlinkCardOverlaySettings()
        
        // Comment out this if you want disable edit screen
        // settings.enableEditScreen = false

        /** Crate recognizer collection */
        let recognizerList = [blinkCardRecognizer]
        let recognizerCollection: MBCRecognizerCollection = MBCRecognizerCollection(recognizers: recognizerList)

        /** Create your overlay view controller */
        let blinkCardOverlayViewController: MBCBlinkCardOverlayViewController =
            MBCBlinkCardOverlayViewController(settings: settings, recognizerCollection: recognizerCollection, delegate: context.coordinator)

        /** Create recognizer view controller with wanted overlay view controller */
        let recognizerRunneViewController: UIViewController =
            MBCViewControllerFactory.recognizerRunnerViewController(withOverlayViewController: blinkCardOverlayViewController)!
        
        return recognizerRunneViewController
    }
    
    func updateUIViewController(_ uiViewController: UIViewControllerType, context: Context) {
        
    }
    
}

