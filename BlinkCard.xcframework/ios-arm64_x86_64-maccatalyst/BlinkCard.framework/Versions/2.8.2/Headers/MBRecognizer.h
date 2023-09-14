//
//  MBRecognizer.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 21/11/2017.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MBMicroblinkDefines.h"
#import "MBEntity.h"
#import "MBRecognizerResult.h"

@class MBCSignedPayload;

NS_ASSUME_NONNULL_BEGIN

/**
 * Base class for all recognizers
 */
MB_CLASS_AVAILABLE_IOS(13.0)
@interface MBCRecognizer : MBCEntity

/**
 * Base recognizer result.
 */
@property (nonatomic, readonly, weak) MBCRecognizerResult *baseResult;

- (UIInterfaceOrientationMask)getOptimalHudOrientation;

/**
 * Returns the signed JSON representation of this entity's current state as a MBCSignedPayload.
 *
 * @return signed JSON representation of this entity's current state.
 */
- (MBCSignedPayload *)toSignedJson;

@end

NS_ASSUME_NONNULL_END
