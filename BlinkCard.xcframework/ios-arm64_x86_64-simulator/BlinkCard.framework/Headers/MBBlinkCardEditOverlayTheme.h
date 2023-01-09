//
//  MBBlinkCardEditOverlayTheme.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 19/10/2020.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

MB_CLASS_AVAILABLE_IOS(13.0)
@interface MBCBlinkCardEditOverlayTheme : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)sharedInstance NS_SWIFT_NAME(shared());

/**
 * Placeholder text color
 *
 * Default: gray
 */
@property(nonatomic, strong) UIColor *placeholderTextColor;

/**
 * Floating title idel mode color
 *
 * Default: gray
 */
@property(nonatomic, strong) UIColor *floatingTitleIdleModeColor;

/**
 * Floating title edit mode color
 *
 * Default: Microblink blue
 */
@property(nonatomic, strong) UIColor *floatingTitleFloatingModeColor;

/**
 * Floating title edit mode color
 *
 * Default: gray
 */
@property(nonatomic, strong) UIColor *floatingTitleEditedModeColor;

/**
 * Floating title error mode color
 *
 * Default: Microblink red
 */
@property(nonatomic, strong) UIColor *floatingTitleErrorModeColor;

/**
 * Separator view color
 *
 * Default: gray
 */
@property(nonatomic, strong) UIColor *separatorViewColor;

/**
 * Confirm button background color
 *
 * Default: Microblink blue
 */
@property(nonatomic, strong) UIColor *confirmButtonColor;

/**
 * Confirm button title color
 *
 * Default: white
 */
@property(nonatomic, strong) UIColor *confirmButtonTitleColor;

/**
 * Floating textfield font
 *
 * Default: System 17
 */
@property(nonatomic, strong) UIFont *textFieldFont;

/**
 * Floating textfield font
 *
 * Default: System 13
 */
@property(nonatomic, strong) UIFont *floatingTitleFont;

/**
 * Floating textfield font
 *
 * Default: System 17 semibold
 */
@property(nonatomic, strong) UIFont *confirmButtonFont;

/**
 * Left image
 *
 * Default: null
 */
@property(nonatomic, strong, nullable) UIImage *leadingImage;

/**
 * Edit image
 *
 * Default: close-icon
 */
@property(nonatomic, strong, nullable) UIImage *editButtonImage;

/**
 * Confirm button corner radius
 *
 * Default: 10
 */
@property(nonatomic, assign) CGFloat confirmButtonCornerRadius;

@end

NS_ASSUME_NONNULL_END
