//
//  CustomOverlay.swift
//  BlinkCard-sample-Swift
//
//  Created by Jura Skrlec on 02/07/2020.
//  Copyright © 2020 Microblink. All rights reserved.
//

import BlinkCard

class CustomOverlay: MBCCustomOverlayViewController, MBCScanningRecognizerRunnerViewControllerDelegate,
        MBCFirstSideFinishedRecognizerRunnerViewControllerDelegate {

    @IBOutlet weak var tooltipLabel: UILabel!
    
    var blinkCardEditScreen: MBCBlinkCardEditViewController?
    var blinkcardNavigationViewController: MBCBlinkCardEditNavigationController?
    var blinkCardRecognizerResult: MBCBlinkCardRecognizerResult?

    static func initFromStoryboard() -> CustomOverlay {

        let viewController = UIStoryboard(name: "Main", bundle: nil).instantiateViewController(withIdentifier: "CustomOverlay")

        guard let customOverlay = viewController as? CustomOverlay else {
            fatalError("CustomOverlay should always be an instance of \(CustomOverlay.self) here because we instantiate it from the Storyboard")
        }

        return customOverlay
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        super.scanningRecognizerRunnerViewControllerDelegate = self
        super.metadataDelegates.firstSideFinishedRecognizerRunnerViewControllerDelegate = self

        self.tooltipLabel.text = "Scan Front Side"
    }
    
    func recognizerRunnerViewControllerDidFinishScanning(_ recognizerRunnerViewController: UIViewController & MBCRecognizerRunnerViewController, state: MBCRecognizerResultState) {
        // This is done on background thread
        if state == .valid {
            recognizerRunnerViewController.pauseScanning()

            DispatchQueue.main.async {

                var message: String = ""
                var title: String = ""

                for recognizer in self.recognizerCollection.recognizerList where
                    recognizer.baseResult?.resultState == .valid {

                    if recognizer is MBCBlinkCardRecognizer {
                        let blinkCardRecognizer = recognizer as? MBCBlinkCardRecognizer
                        title = "BlinkCard"
                        message = (blinkCardRecognizer?.result.description)!
                        self.blinkCardRecognizerResult = blinkCardRecognizer?.result
                    }
                }

                let alertController: UIAlertController = UIAlertController.init(title: title, message: message, preferredStyle: UIAlertController.Style.alert)

                let okAction: UIAlertAction = UIAlertAction.init(title: "OK", style: UIAlertAction.Style.default,
                                                                 handler: { (_) -> Void in
                                                                    self.showEditScreen(blinkCardRecognizerResult: self.blinkCardRecognizerResult!)
                })
                alertController.addAction(okAction)
                self.present(alertController, animated: true, completion: nil)
            }
        }
    }

    func recognizerRunnerViewControllerDidFinishRecognition(ofFirstSide recognizerRunnerViewController: UIViewController & MBCRecognizerRunnerViewController) {

        DispatchQueue.main.async {
            self.tooltipLabel.text = "Scan Back Side"
        }
    }

    @IBAction func didTapClose(_ sender: Any) {
        self.recognizerRunnerViewController?.overlayViewControllerWillCloseCamera(self)
        self.dismiss(animated: true, completion: nil)
    }
    
    func showEditScreen(blinkCardRecognizerResult: MBCBlinkCardRecognizerResult) {
        blinkCardEditScreen = MBCBlinkCardEditViewController(blinkCardRecognizerResult: blinkCardRecognizerResult, fieldConfiguration: MBCBlinkCardEditFieldConfiguration(), delegate: self)
        blinkcardNavigationViewController = MBCBlinkCardEditNavigationController(rootViewController: blinkCardEditScreen!)
        self.present(blinkcardNavigationViewController!, animated: true, completion: nil)
    }
}

extension CustomOverlay: MBCBlinkCardEditViewControllerDelegate {
    func blinkCardEditViewControllerDidFinishEditing(_ blinkCardEditViewController: MBCBlinkCardEditViewController, editResult: MBCBlinkCardEditResult) {
        self.recognizerRunnerViewController?.pauseScanning()
        
        /** Needs to be called on main thread beacuse everything prior is on background thread */
        DispatchQueue.main.async {
            // present the alert view with scanned results
            
            let alertController: UIAlertController = UIAlertController.init(title: "BlinkCard Edit Results", message: editResult.description, preferredStyle: .alert)
            
            let okAction: UIAlertAction = UIAlertAction.init(title: "OK", style: .default,
                                                             handler: { (action) -> Void in
                                                                self.blinkCardEditScreen?.dismiss(animated: true, completion: nil)
                                                                self.dismiss(animated: true, completion: nil)
            })
            alertController.addAction(okAction)
            blinkCardEditViewController.present(alertController, animated: true, completion: nil)
        }
    }
    
    func blinkCardEditViewControllerDidTapClose(_ blinkCardEditViewController: MBCBlinkCardEditViewController) {
        
        DispatchQueue.main.async {
            blinkCardEditViewController.dismiss(animated: true, completion: nil)
        }
    }
    
    
}

