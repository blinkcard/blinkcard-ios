//
//  CustomOverlay.swift
//  BlinkCard-sample-Swift
//
//  Created by Jura Skrlec on 02/07/2020.
//  Copyright © 2020 Microblink. All rights reserved.
//

import Microblink

class CustomOverlay: MBCustomOverlayViewController, MBScanningRecognizerRunnerViewControllerDelegate,
        MBFirstSideFinishedRecognizerRunnerViewControllerDelegate {

    @IBOutlet weak var tooltipLabel: UILabel!

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

    func recognizerRunnerViewController(_ recognizerRunnerViewController: UIViewController & MBRecognizerRunnerViewController,
                                        didFinishScanningWith state: MBRecognizerResultState) {

        // This is done on background thread
        if state == MBRecognizerResultState.valid {
            recognizerRunnerViewController.pauseScanning()

            DispatchQueue.main.async {

                var message: String = ""
                var title: String = ""

                for recognizer in self.recognizerCollection.recognizerList where
                    recognizer.baseResult?.resultState == MBRecognizerResultState.valid {

                    if recognizer is MBBlinkCardRecognizer {
                        let blinkCardRecognizer = recognizer as? MBBlinkCardRecognizer
                        title = "BlinkCard"
                        message = (blinkCardRecognizer?.result.description)!
                    }
                }

                let alertController: UIAlertController = UIAlertController.init(title: title, message: message, preferredStyle: UIAlertController.Style.alert)

                let okAction: UIAlertAction = UIAlertAction.init(title: "OK", style: UIAlertAction.Style.default,
                                                                 handler: { (_) -> Void in
                                                                    self.dismiss(animated: true, completion: nil)
                })
                alertController.addAction(okAction)
                self.present(alertController, animated: true, completion: nil)
            }
        }
    }

    func recognizerRunnerViewControllerDidFinishRecognition(ofFirstSide recognizerRunnerViewController: UIViewController & MBRecognizerRunnerViewController) {

        DispatchQueue.main.async {
            self.tooltipLabel.text = "Scan Back Side"
        }
    }

    @IBAction func didTapClose(_ sender: Any) {
        self.recognizerRunnerViewController?.overlayViewControllerWillCloseCamera(self)
        self.dismiss(animated: true, completion: nil)
    }

}

