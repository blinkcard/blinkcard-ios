//
//  MBOcrRecognizerRunnerDelegate.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 20/12/2017.
//

@class MBCRecognizerRunner;
@class MBCOcrLayout;

/**
 * Protocol for obtaining ocr results
 */
@protocol MBCOcrRecognizerRunnerDelegate <NSObject>
@required

/**
 * Called when Scanning library has MBCOcrLayout available and ready to be displayed on UI.
 * NOTE: This method is called on background processing thread. Make sure that you dispatch all your UI API calls to main thread.
 */
- (void)recognizerRunner:(nonnull MBCRecognizerRunner *)recognizerRunner
      didObtainOcrResult:(nonnull MBCOcrLayout *)ocrResult
          withResultName:(nonnull NSString *)resultName;

@end
