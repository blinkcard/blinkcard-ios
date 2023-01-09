//
//  MBSubview.h
//  BarcodeFramework
//
//  Created by Jura on 06/06/14.
//  Copyright (c) 2015 Microblink Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MBMicroblinkDefines.h"

NS_ASSUME_NONNULL_BEGIN


@protocol MBCSubviewDelegate;

/**
 Base class for all overlay subviews
 */
MB_CLASS_AVAILABLE_IOS(13.0)
@interface MBCSubview : UIView

/** Delegate which is notified on Overlay events */
@property (nonatomic, weak, nullable) id<MBCSubviewDelegate> delegate;

@end

/**
 * Protocol which all objects interested in receiving information about overlay subviews need to implement
 */
@protocol MBCSubviewDelegate <NSObject>

/** Delegate method called when animation starts */
- (void)subviewAnimationDidStart:(MBCSubview *)subview;

/** Delegate method called when animation finishes */
- (void)subviewAnimationDidFinish:(MBCSubview *)subview;

@end

NS_ASSUME_NONNULL_END
