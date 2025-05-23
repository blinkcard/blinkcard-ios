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
MB_CLASS_AVAILABLE_IOS(13.0) MB_FINAL
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

/**
* Instructions for the user to move the document closer.
* Default: Move closer
*/
@property(nonatomic, strong) NSString *errorMoveCloser;

/**
* Instructions for the user to move the document farther.
* Default: Move farther
*/
@property(nonatomic, strong) NSString *errorMoveFarther;

/**
* Instructions for the user to move the document from the edge.
* Default: Move the document from the edge
*/
@property(nonatomic, strong) NSString *errorDocumentTooCloseToEdge;

/**
* Instructions for the user when wrong side is being scanned.
* Default: Flip the card over
*/
@property(nonatomic, strong) NSString *scanningWrongSideMessage;

/**
* Option to configure when the onboarding help tooltip will appear.
* Default: 8.0
*/
@property(nonatomic, assign) NSTimeInterval onboardingButtonTooltipDelay;

/**
* Defines whether button for presenting onboarding screens will be present on screen.
* Default: YES
*/
@property(nonatomic, assign) BOOL showOnboardingInfo;

/**
* Defines whether tutorial alert will be presented on appear.
* Default: YES
*/
@property(nonatomic, assign) BOOL showIntroductionDialog;

@end

NS_ASSUME_NONNULL_END
