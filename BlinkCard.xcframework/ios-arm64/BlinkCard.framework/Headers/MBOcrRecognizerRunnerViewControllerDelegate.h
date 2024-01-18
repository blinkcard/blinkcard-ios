//
//  MBOcrRecognizerRunnerViewDelegate.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 18/12/2017.
//

#import <Foundation/Foundation.h>
#import "MBOcrLayout.h"
#import "MBRecognizerRunnerViewController.h"

@class MBCOcrLayout;
@protocol MBCRecognizerRunnerViewController;

/**
 * Protocol for obtaining ocr results
 */
@protocol MBCOcrRecognizerRunnerViewControllerDelegate <NSObject>
@required

/**
 * Called when scanning library has MBCOcrLayout ready to be displayed on UI.
 * NOTE: This method is called on background processing thread. Make sure that you dispatch all your UI API calls to main thread.
 */
- (void)recognizerRunnerViewController:(nonnull UIViewController<MBCRecognizerRunnerViewController> *)recognizerRunnerViewController
                    didObtainOcrResult:(nonnull MBCOcrLayout *)ocrResult
                        withResultName:(nonnull NSString *)resultName;

@end
