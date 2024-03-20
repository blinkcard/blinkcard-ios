//
//  ViewController.m
//  BlinkCard-Sample-ObjC
//
//  Created by Jure Čular on 4/11/19.
//  Copyright © 2019 Microblink. All rights reserved.
//

#import "ViewController.h"
#import <UIKit/UIKit.h>
#import <BlinkCard/BlinkCard.h>

@interface ViewController () <MBCBlinkCardOverlayViewControllerDelegate>

@property (nonatomic, nonnull) MBCBlinkCardRecognizer *blinkCardRecognizer;

@property (nonatomic, strong) NSString *licenseErrorMessage;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
        
    // Valid until: 2024-05-16
    [[MBCMicroblinkSDK sharedInstance] setLicenseResource:@"license" withExtension:@"lic" inSubdirectory:@"" forBundle:NSBundle.mainBundle errorCallback:^(MBCLicenseError licenseError) {
        switch (licenseError) {
            case MBCLicenseErrorInvalidLicense:
                self.licenseErrorMessage = @"Invalid license";
                break;
            case MBCLicenseErrorNetworkRequired:
                self.licenseErrorMessage = @"Network required";
                break;
            case MBCLicenseErrorUnableToDoRemoteLicenceCheck:
                self.licenseErrorMessage = @"Unable to do remote license check";
                break;
            case MBCLicenseErrorLicenseIsLocked:
                self.licenseErrorMessage = @"License is locked";
                break;
            case MBCLicenseErrorLicenseCheckFailed:
                self.licenseErrorMessage = @"License check failed";
                break;
            default:
                break;
        }
    }];
    
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"License Error" message:self.licenseErrorMessage preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [self dismissViewControllerAnimated:YES completion:nil];
    }];
    
    [alertController addAction:okAction];
}

- (IBAction)didTapScan:(id)sender {
    self.blinkCardRecognizer = [[MBCBlinkCardRecognizer alloc] init];
    self.blinkCardRecognizer.returnFullDocumentImage = YES;
    
    MBCRecognizerCollection *recognizerCollection = [[MBCRecognizerCollection alloc] initWithRecognizers:@[self.blinkCardRecognizer]];
    MBCBlinkCardOverlaySettings *overlaySettings = [[MBCBlinkCardOverlaySettings alloc] init];
    
    MBCBlinkCardOverlayViewController *blinkCardOveralyViewController = [[MBCBlinkCardOverlayViewController alloc] initWithSettings:overlaySettings recognizerCollection:recognizerCollection delegate:self];
    
    UIViewController<MBCRecognizerRunnerViewController>* recognizerRunnerViewController = [MBCViewControllerFactory recognizerRunnerViewControllerWithOverlayViewController:blinkCardOveralyViewController];
    recognizerRunnerViewController.modalPresentationStyle = UIModalPresentationFullScreen;
    
    [self presentViewController:recognizerRunnerViewController animated:YES completion:nil];
}

- (void)blinkCardOverlayViewControllerDidFinishScanning:(nonnull MBCBlinkCardOverlayViewController *)blinkCardOverlayViewController state:(MBCRecognizerResultState)state {
    
    [blinkCardOverlayViewController.recognizerRunnerViewController pauseScanning];

    NSString *title;
    NSString *message;
    
    if (self.blinkCardRecognizer.result.resultState == MBCRecognizerResultStateValid) {
        title = @"Payment card";
        
        UIImage *fullDocumentImage = self.blinkCardRecognizer.result.firstSideFullDocumentImage.image;
        NSLog(@"Got payment card image with width: %f, height: %f", fullDocumentImage.size.width, fullDocumentImage.size.height);
        message = self.blinkCardRecognizer.result.description;
    }
    
    dispatch_async(dispatch_get_main_queue(), ^{
        
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:title message:message preferredStyle:UIAlertControllerStyleAlert];
        UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
            [self dismissViewControllerAnimated:YES completion:nil];
        }];
        
        [alertController addAction:okAction];
        [blinkCardOverlayViewController presentViewController:alertController animated:YES completion:nil];
    });
}

- (void)blinkCardOverlayViewControllerDidTapClose:(nonnull MBCBlinkCardOverlayViewController *)blinkCardOverlayViewController {
    [blinkCardOverlayViewController dismissViewControllerAnimated:YES completion:nil];
}

- (void)blinkCardOverlayViewControllerDidFinishEditing:(MBCBlinkCardOverlayViewController *)blinkCardOverlayViewController editResult:(MBCBlinkCardEditResult *)editResult {
    
    [blinkCardOverlayViewController.recognizerRunnerViewController pauseScanning];
    
    dispatch_async(dispatch_get_main_queue(), ^{
        
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"BlinkCard Edit Results" message:editResult.description preferredStyle:UIAlertControllerStyleAlert];
        UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
            [self dismissViewControllerAnimated:YES completion:nil];
        }];
        
        [alertController addAction:okAction];
        [blinkCardOverlayViewController.blinkCardEditViewController presentViewController:alertController animated:YES completion:nil];
    });
}
@end
