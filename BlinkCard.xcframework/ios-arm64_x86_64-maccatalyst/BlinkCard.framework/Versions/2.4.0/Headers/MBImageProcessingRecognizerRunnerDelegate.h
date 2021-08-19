//
//  MBImageProcessingDelegate.h
//  Microblink
//
//  Created by DoDo on 07/05/2018.
//

@class MBCRecognizerRunner;
@class MBCImage;

@protocol MBCImageProcessingRecognizerRunnerDelegate <NSObject>
@required

/**
 * Called when MBCRecognizerRunner finishes processing given image.
 * NOTE: This method is called on background processing thread. Make sure that you dispatch all your UI API calls to main thread.
 */
- (void) recognizerRunner:(nonnull MBCRecognizerRunner *)recognizerRunner didFinishProcessingImage:(nonnull MBCImage *)image;

@end
