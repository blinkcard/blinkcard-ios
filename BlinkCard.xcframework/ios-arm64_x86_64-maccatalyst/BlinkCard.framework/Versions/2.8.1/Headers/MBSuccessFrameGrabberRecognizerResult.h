//
//  MBSuccessFrameGrabberRecognizerResult.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 22/12/2017.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBRecognizerResult.h"

@class MBCImage;

NS_ASSUME_NONNULL_BEGIN

/**
 * A recognizer that returns SuccessFrameGrabber result.
 */
MB_CLASS_AVAILABLE_IOS(13.0)

@interface MBCSuccessFrameGrabberRecognizerResult : MBCRecognizerResult<NSCopying>

MB_INIT_UNAVAILABLE

/**
 * Success frame MBCImage of successful frame
 */
@property (nonatomic, strong, readonly) MBCImage *successFrame;

@end

NS_ASSUME_NONNULL_END
