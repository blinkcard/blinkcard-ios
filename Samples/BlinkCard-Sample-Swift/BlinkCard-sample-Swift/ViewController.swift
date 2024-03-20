//
//  ViewController.swift
//  BlinkCard-Sample-Swift
//
//  Created by Jure Čular on 4/11/19.
//  Copyright © 2019 Microblink. All rights reserved.
//

import UIKit
import BlinkCard

class ViewController: UIViewController {
    var blinkCardRecognizer: MBCBlinkCardRecognizer!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        var licenseErrorMessage = ""
        
        // Valid until: 2024-05-16
        MBCMicroblinkSDK.shared().setLicenseResource("license", withExtension: "lic", inSubdirectory: "", for: .main) { (licenseError) in
            switch licenseError {
            case .invalidLicense:
                licenseErrorMessage = "Invalid license"
            case .networkRequired:
                licenseErrorMessage = "Network required"
            case .unableToDoRemoteLicenceCheck:
                licenseErrorMessage = "Unable to do remote license check"
            case .licenseIsLocked:
                licenseErrorMessage = "License is locked"
            case .licenseCheckFailed:
                licenseErrorMessage = "License check failed"
            case .permissionExpired:
                licenseErrorMessage = "Permission expired"
            case .payloadCorrupted:
                licenseErrorMessage = "Payload corrupted"
            case .payloadSignatureVerificationFailed:
                licenseErrorMessage = "Payload signature verification failed"
            case .incorrectTokenState:
                licenseErrorMessage = "Incorrect token state"
            @unknown default:
                licenseErrorMessage = "Unknown error"
            }
        }
        
        let alert = UIAlertController(title: "License Error", message: licenseErrorMessage, preferredStyle: UIAlertController.Style.alert)
        alert.addAction(UIAlertAction(title: "OK", style: UIAlertAction.Style.default, handler: nil))

        self.present(alert, animated: true, completion: nil)
    }

    @IBAction func didTapScan(_ sender: Any) {
        blinkCardRecognizer = MBCBlinkCardRecognizer()
        blinkCardRecognizer.returnFullDocumentImage = true
        
        let recognizerCollection = MBCRecognizerCollection(recognizers: [blinkCardRecognizer])
        
        let blinkCardOverlaySettings = MBCBlinkCardOverlaySettings()
        let blinkCardOverlayViewController = MBCBlinkCardOverlayViewController(settings: blinkCardOverlaySettings, recognizerCollection: recognizerCollection, delegate: self)
        
        let recognizerRunnerViewController: UIViewController = MBCViewControllerFactory.recognizerRunnerViewController(withOverlayViewController: blinkCardOverlayViewController)!
        
        recognizerRunnerViewController.modalPresentationStyle = .fullScreen
        present(recognizerRunnerViewController, animated: true, completion: nil)
    }
    
    @IBAction func didTapCustomUI(_ sender: Any) {
        blinkCardRecognizer = MBCBlinkCardRecognizer()
        blinkCardRecognizer.returnFullDocumentImage = true

        let recognizerList = [blinkCardRecognizer!]
        let recognizerCollection = MBCRecognizerCollection(recognizers: recognizerList)

        let customOverlayViewController: CustomOverlay = CustomOverlay.initFromStoryboard()

        /** This has to be called for custom controller */
        customOverlayViewController.reconfigureRecognizers(recognizerCollection)

        /** Create recognizer view controller with wanted overlay view controller */
        let recognizerRunneViewController: UIViewController =
            MBCViewControllerFactory.recognizerRunnerViewController(withOverlayViewController: customOverlayViewController)!

        recognizerRunneViewController.modalPresentationStyle = .fullScreen

        /** Present the recognizer runner view controller. You can use other presentation methods as well (instead of presentViewController) */
        self.present(recognizerRunneViewController, animated: true, completion: nil)
    }
}

extension ViewController: MBCBlinkCardOverlayViewControllerDelegate {
    func blinkCardOverlayViewControllerDidFinishScanning(_ blinkCardOverlayViewController: MBCBlinkCardOverlayViewController, state: MBCRecognizerResultState) {
        /** This is done on background thread */
        blinkCardOverlayViewController.recognizerRunnerViewController?.pauseScanning()
        
        var message: String = ""
        var title: String = ""
        
        if blinkCardRecognizer.result.resultState == .valid {
            title = "Payment card"
            
            let fullDocumentImage: UIImage! = blinkCardRecognizer.result.firstSideFullDocumentImage?.image
            print("Got payment card image with width: \(fullDocumentImage.size.width), height: \(fullDocumentImage.size.height)")
            
            // Save the string representation of the code
            message = blinkCardRecognizer.result.description
        }
        
        /** Needs to be called on main thread beacuse everything prior is on background thread */
        DispatchQueue.main.async {
            // present the alert view with scanned results
            
            let alertController: UIAlertController = UIAlertController.init(title: title, message: message, preferredStyle: .alert)
            
            let okAction: UIAlertAction = UIAlertAction.init(title: "OK", style: .default,
                                                             handler: { (action) -> Void in
                                                                self.dismiss(animated: true, completion: nil)
            })
            alertController.addAction(okAction)
            blinkCardOverlayViewController.present(alertController, animated: true, completion: nil)
        }
    }
    
    func blinkCardOverlayViewControllerDidTapClose(_ blinkCardOverlayViewController: MBCBlinkCardOverlayViewController) {
        self.dismiss(animated: true, completion: nil)
    }
    
    func blinkCardOverlayViewControllerDidFinishEditing(_ blinkCardOverlayViewController: MBCBlinkCardOverlayViewController, editResult: MBCBlinkCardEditResult) {
        blinkCardOverlayViewController.recognizerRunnerViewController?.pauseScanning()
        
        /** Needs to be called on main thread beacuse everything prior is on background thread */
        DispatchQueue.main.async {
            // present the alert view with scanned results
            
            let alertController: UIAlertController = UIAlertController.init(title: "BlinkCard Edit Results", message: editResult.description, preferredStyle: .alert)
            
            let okAction: UIAlertAction = UIAlertAction.init(title: "OK", style: .default,
                                                             handler: { (action) -> Void in
                                                                self.dismiss(animated: true, completion: nil)
            })
            alertController.addAction(okAction)
            blinkCardOverlayViewController.blinkCardEditViewController?.present(alertController, animated: true, completion: nil)
        }
    }
    
}


