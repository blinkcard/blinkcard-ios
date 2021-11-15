//
//  MBBlinkCardOverlayTheme.h
//  BlinkShowcaseDev
//
//  Created by Jura Skrlec on 20/11/2020.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"

NS_ASSUME_NONNULL_BEGIN
MB_CLASS_AVAILABLE_IOS(9.0)
@interface MBCBlinkCardOverlayTheme : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)sharedInstance NS_SWIFT_NAME(shared());

/**
 * Flashlight warning font
 *
 * Default: System (iPhone - 14pt, iPad - 16pt)
 */
@property (nonatomic, strong) UIFont *flashlightWarningFont;

/**
 * Flashlight warning background color
 *
 * Default: #3A3A3C
*/
@property (nonatomic, strong) UIColor *flashlightWarningBackgroundColor;

/**
 * Flashlight warning text color
 *
 * Default: white
*/
@property (nonatomic, strong) UIColor *flashlightWarningTextColor;

/**
 * Flashlight warning corner radius
 *
 * Default: 4
*/
@property (nonatomic, assign) CGFloat flashlightWarningCornerRadius;

/**
 * Type it instead button font
 *
 * Default: System (iPhone - 14pt, iPad - 16pt) - semibold
 */
@property(nonatomic, strong) UIFont *editButtonFont;

/**
 * Type it instead button color
 *
 * Default: white
 */
@property(nonatomic, strong) UIColor *editButtonColor;

/**
 * TScanning status label font
 *
 * Default: System 16.pt Bold
 */
@property(nonatomic, strong) UIFont *scanningStatusLabelFont;

/**
 * Scanning status label color
 *
 * Default: white
 */
@property(nonatomic, strong) UIColor *scanningStatusLabelColor;

@end

NS_ASSUME_NONNULL_END
