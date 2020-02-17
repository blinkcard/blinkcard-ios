//
//  ViewController.swift
//  BlinkCard-Sample-Swift
//
//  Created by Jure Čular on 4/11/19.
//  Copyright © 2019 Microblink. All rights reserved.
//

import UIKit
import Microblink

class ViewController: UIViewController {
    var blinkCardRecognizer: MBBlinkCardRecognizer!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Valid until: 2020-07-16
        MBMicroblinkSDK.sharedInstance().setLicenseResource("license", withExtension: "txt", inSubdirectory: "", for: Bundle.main)
    }

    @IBAction func didTapScan(_ sender: Any) {
        blinkCardRecognizer = MBBlinkCardRecognizer()
        blinkCardRecognizer.extractCvv = false
        blinkCardRecognizer.returnFullDocumentImage = true
        
        let recognizerCollection = MBRecognizerCollection(recognizers: [blinkCardRecognizer])
        
        let blinkCardOverlaySettings = MBBlinkCardOverlaySettings()
        let blinkCardOverlayViewController = MBBlinkCardOverlayViewController(settings: blinkCardOverlaySettings, recognizerCollection: recognizerCollection, delegate: self)
        
        let recognizerRunnerViewController: UIViewController = MBViewControllerFactory.recognizerRunnerViewController(withOverlayViewController: blinkCardOverlayViewController)
        
        present(recognizerRunnerViewController, animated: true, completion: nil)
    }
}

extension ViewController: MBBlinkCardOverlayViewControllerDelegate {
    func blinkCardOverlayViewControllerDidFinishScanning(_ blinkCardOverlayViewController: MBBlinkCardOverlayViewController, state: MBRecognizerResultState) {
        /** This is done on background thread */
        blinkCardOverlayViewController.recognizerRunnerViewController?.pauseScanning()
        
        var message: String = ""
        var title: String = ""
        
        if blinkCardRecognizer.result.resultState == MBRecognizerResultState.valid {
            title = "Payment card"
            
            let fullDocumentImage: UIImage! = blinkCardRecognizer.result.fullDocumentFrontImage?.image
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
    
    func blinkCardOverlayViewControllerDidTapClose(_ blinkCardOverlayViewController: MBBlinkCardOverlayViewController) {
        self.dismiss(animated: true, completion: nil)
    }
}

