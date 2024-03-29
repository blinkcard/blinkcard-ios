//
//  MBDisplayableQuadDetection.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 08/12/2017.
//

#import "MBDisplayableDetection.h"
#import "MBQuadrangle.h"

#import "MBMicroblinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Represents a detection that can be displayed on screen.
 */
MB_CLASS_AVAILABLE_IOS(13.0)
@interface MBCDisplayableQuadDetection : MBCDisplayableDetection

/**
 * Exact location of detected object on image.
 * Contains 4 points of detected object's corners.
 */
@property (nonatomic, strong) MBCQuadrangle *detectionLocation;

@end

NS_ASSUME_NONNULL_END
