//
//  MBStringProcessingRecognizerRunnerDelegate.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 18/06/2018.
//

@class MBCRecognizerRunner;

@protocol MBCStringProcessingRecognizerRunnerDelegate <NSObject>
@required

/**
 * Called when MBCRecognizerRunner finishes processing given string.
 * NOTE: This method is called on background processing thread. Make sure that you dispatch all your UI API calls to main thread.
 */
- (void)recognizerRunner:(nonnull MBCRecognizerRunner *)recognizerRunner didFinishProcessingString:(nonnull NSString *)string;

@end
