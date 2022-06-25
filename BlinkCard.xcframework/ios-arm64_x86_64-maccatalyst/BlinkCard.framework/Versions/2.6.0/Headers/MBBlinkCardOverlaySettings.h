//
//  MBBlinkCardOverlaySettings.h
//  MicroBlink
//
//  Created by Jura on 31/01/2019.
//

#import "MBBaseOcrOverlaySettings.h"
#import "MBBlinkCardEditFieldConfiguration.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Settings class containing UI information for BlinkCard
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBCBlinkCardOverlaySettings : MBCBaseOcrOverlaySettings

/**
 * Returns/sets glare status message that is shown if glare detection is turned on
 * and it is shown if glare is detected.
 *
 * Default: string defined by "mb_tooltip_glare"
 * key in strings file in Microblink.bundle
 */
@property(nonatomic, strong) NSString *glareStatusMessage;

/**
 * Returns/sets status message that is shows when front side of payment card
 * should be scanned.
 *
 * Default: string defined by "mb_instructions_scan_front" key in
 * key in strings file in Microblink.bundle
 */
@property(nonatomic, strong) NSString *frontSideMessage;

/**
 * Returns/sets status message that is shows when back side of payment card
 * should be scanned.
 *
 * Default: string defined by "mb_instructions_scan_back_side" key in
 * key in strings file in Microblink.bundle
 */
@property(nonatomic, strong) NSString *backSideMessage;

/**
 * Defines whether glare warning will be displayed when user turn on a flashlight
 *
 * Default: YES
*/
@property(nonatomic, assign) BOOL showFlashlightWarning;

/**
 * Defines whether manual edit screen is enabled
 *
 * Default: YES
*/
@property(nonatomic, assign) BOOL enableEditScreen;

/**
 * Defines edit configuration settings
 */
@property(nonatomic, strong) MBCBlinkCardEditFieldConfiguration *fieldConfiguration;

@end

NS_ASSUME_NONNULL_END
