//
//  MBImage.h
//  BlinkIdFramework
//
//  Created by Dino on 25/02/16.
//  Copyright © 2016 Microblink Ltd. All rights reserved.
//

#import "Foundation/Foundation.h"
#import "CoreMedia/CoreMedia.h"
#import <UIKit/UIKit.h>
#import "MBMicroblinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

/// Enum which defines video rotation angle or capture connection's video orientation.
typedef NS_ENUM(NSInteger, MBCVideoRotationAngle) {
    // Landscape left
    MBCVideoRotationAngleLandscapeLeft,
    // Portrait
    MBCVideoRotationAnglePortrait,
    // Landscape right
    MBCVideoRotationAngleLandscapeRight,
    // Portrait upside down
    MBCVideoRotationAnglePortraitUpsideDown
};

/**
 * Enum which describes text orientation on an image.
 */
typedef NS_ENUM(NSInteger, MBCProcessingOrientation) {
    /** Text oriented same as picture */
    MBCProcessingOrientationUp,
    /** Text is rotated 90 degrees clockwise */
    MBCProcessingOrientationRight,
    /** Text is upside down */
    MBCProcessingOrientationDown,
    /** Text is rotated 90 degrees counterclockwise */
    MBCProcessingOrientationLeft
};

/**
 * Object which represents an image.
 */
MB_CLASS_AVAILABLE_IOS(13.0)
@interface MBCImage : NSObject

/**
 * UIImage of wrapped image.
 * If this MBCImage wasn't created with UIImage, UIImage will be created with first access of this property.
 */
@property (nonatomic, readonly, nullable) UIImage *image;

/**
 * Region of the image used for scanning, where the whole image is specified with CGRectMake(0.0, 0.0, 1.0, 1.0).
 */
@property (nonatomic) CGRect roi;

/**
 * Processing orientation of image. This is used in OCR where you can specify character orientation.
 *
 * Default: MBCProcessingOrientationUp
 */
@property (nonatomic) MBCProcessingOrientation orientation;

/**
 * Tells whether camera input images should be mirrored horizontally before processing
 *
 * Default: NO
 */
@property (nonatomic) BOOL mirroredHorizontally;

/**
 * Tells whether camera input images should be mirrored vertically before processing
 *
 * Default: NO
 */
@property (nonatomic) BOOL mirroredVertically;


/**
 * If YES, the image will prior to processing go through frame quality estimation phase, which might discard the frame
 *
 * Default: NO.
 */
@property (nonatomic) BOOL estimateFrameQuality;

/**
 *  Property which tells if this frame is a camera or a single photo frame.
 *  This is important for image processing.
 *
 *  Default: YES if created with CMSampleBuffer, NO if created with UIImage
 */
@property (nonatomic) BOOL cameraFrame;

/// Connection orientation.
/// Default: `MBCVideoRotationAngleLandscapeRight` - landscape right.
@property (nonatomic) MBCVideoRotationAngle videoRotationAngle;

/**
 * Creates MBCImage around UIImage.
 */
+ (instancetype)imageWithUIImage:(UIImage *)image;

/**
 * Creates MBCImage around CVImageBufferRef.
 */
+ (instancetype)imageWithCmSampleBuffer:(CMSampleBufferRef)buffer;

/**
 * Creates MBCImage around CVPixelBufferRef.
 */
+ (instancetype)imageWithCvPixelBuffer:(CVPixelBufferRef)buffer orientation:(UIImageOrientation)orientation;

@end

NS_ASSUME_NONNULL_END
