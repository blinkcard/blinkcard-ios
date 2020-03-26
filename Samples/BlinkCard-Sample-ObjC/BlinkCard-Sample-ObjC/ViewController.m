//
//  ViewController.m
//  BlinkCard-Sample-ObjC
//
//  Created by Jure Čular on 4/11/19.
//  Copyright © 2019 Microblink. All rights reserved.
//

#import "ViewController.h"
#import <UIKit/UIKit.h>
#import <Microblink/Microblink.h>

@interface ViewController () <MBBlinkCardOverlayViewControllerDelegate>

@property (nonatomic, nonnull) MBBlinkCardRecognizer *blinkCardRecognizer;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // Valid until: 2020-07-04
    [[MBMicroblinkSDK sharedInstance] setLicenseResource:@"license" withExtension:@"txt" inSubdirectory:@"" forBundle:NSBundle.mainBundle];
}

- (IBAction)didTapScan:(id)sender {
    self.blinkCardRecognizer = [[MBBlinkCardRecognizer alloc] init];
    self.blinkCardRecognizer.extractCvv = NO;
    self.blinkCardRecognizer.returnFullDocumentImage = YES;
    
    MBRecognizerCollection *recognizerCollection = [[MBRecognizerCollection alloc] initWithRecognizers:@[self.blinkCardRecognizer]];
    MBBlinkCardOverlaySettings *overlaySettings = [[MBBlinkCardOverlaySettings alloc] init];
    
    MBBlinkCardOverlayViewController *blinkCardOveralyViewController = [[MBBlinkCardOverlayViewController alloc] initWithSettings:overlaySettings recognizerCollection:recognizerCollection delegate:self];
    
    UIViewController<MBRecognizerRunnerViewController>* recognizerRunnerViewController = [MBViewControllerFactory recognizerRunnerViewControllerWithOverlayViewController:blinkCardOveralyViewController];
    
    [self presentViewController:recognizerRunnerViewController animated:YES completion:nil];
}

- (void)blinkCardOverlayViewControllerDidFinishScanning:(nonnull MBBlinkCardOverlayViewController *)blinkCardOverlayViewController state:(MBRecognizerResultState)state {
    
    [blinkCardOverlayViewController.recognizerRunnerViewController pauseScanning];

    NSString *title;
    NSString *message;
    
    if (self.blinkCardRecognizer.result.resultState == MBRecognizerResultStateValid) {
        title = @"Payment card";
        
        UIImage *fullDocumentImage = self.blinkCardRecognizer.result.fullDocumentFrontImage.image;
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

- (void)blinkCardOverlayViewControllerDidTapClose:(nonnull MBBlinkCardOverlayViewController *)blinkCardOverlayViewController {
    [blinkCardOverlayViewController dismissViewControllerAnimated:YES completion:nil];
}
@end
