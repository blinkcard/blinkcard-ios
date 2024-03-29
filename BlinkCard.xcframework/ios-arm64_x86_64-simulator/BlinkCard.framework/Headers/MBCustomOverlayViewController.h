//
//  MBCustomOverlayViewController.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 25/04/2018.
//

#import "MBOverlayViewController.h"
#import "MBMicroblinkInitialization.h"

#import "MBBaseOverlaySettings.h"
#import "MBRecognizerRunnerViewControllerMetadataDelegates.h"
#import "MBScanningRecognizerRunnerViewControllerDelegate.h"
#import "MBRecognizerRunnerViewControllerDelegate.h"

@class MBCRecognizerCollection;
@class MBCCameraSettings;

NS_ASSUME_NONNULL_BEGIN

/**
 Custom Overlay View Controller is an abstract class for all custom overlay views placed on top View Controller.
 It's responsibility is to provide meaningful and useful interface for the user to interact with.
 */
MB_CLASS_AVAILABLE_IOS(13.0)
@interface MBCCustomOverlayViewController : MBCOverlayViewController

@property (nonatomic, readonly, strong) MBCRecognizerCollection *recognizerCollection;
@property (nonatomic, readonly, strong) MBCCameraSettings *cameraSettings;
@property (nonatomic, strong) MBCRecognizerRunnerViewControllerMetadataDelegates *metadataDelegates;
@property (nonatomic, weak) id<MBCScanningRecognizerRunnerViewControllerDelegate> scanningRecognizerRunnerViewControllerDelegate;
@property (nonatomic, weak) id<MBCRecognizerRunnerViewControllerDelegate> recognizerRunnerViewControllerDelegate;

/**
 * Convenience initializer used for use cases when overlay view controller is instantiated from storyboard.
 * It creates default MBCCameraSettings and empty MBCRecognizerCollection. To add recognizers after this
 * initializer is used, please use reconfigureRecognizers:.
 */
- (instancetype)init;

- (instancetype)initWithRecognizerCollection:(MBCRecognizerCollection *)recognizerCollection cameraSettings:(MBCCameraSettings *)cameraSettings NS_DESIGNATED_INITIALIZER;

/**
 * Scanning region
 * Defines a portion of the screen in which the scanning will be performed.
 * Given as a CGRect with unit coordinating system:
 *
 * @warning Should only be set AFTER RecognizerRunnerViewController has been instantiated with this CustomOverlayViewController, or else it will not have any effect.
 *
 * @example CGRectMake(0.2f, 0.5f, 0.4f, 0.3f) defines a portion of the screen which starts at
 *   20% from the left border
 *   50% from the top
 *   covers 40% of screen width
 *   and 30% of screen heeight
 */
@property (nonatomic) CGRect scanningRegion;

/**
 * If YES, Overlay View Controller will be autorotated independently of ScanningViewController.
 *
 * Default: NO.
 */
@property (nonatomic, assign) BOOL autorotateOverlay;

/**
 * If YES, default camera overlay will display Status bar.
 * Usually, if camera is displayed inside Navigation View Controler, this is reasonable to set to YES.
 *
 * Default: NO.
 */
@property (nonatomic, assign) BOOL showStatusBar;

/**
 * Default: UIInterfaceOrientationMaskPortrait
 */
@property (nonatomic, assign) UIInterfaceOrientationMask supportedOrientations;

/**
 * Reconfigures current recognizer collection to new recognizer collection. Use this method to reconfigure what you wish to scan.
 */
- (void)reconfigureRecognizers:(MBCRecognizerCollection *)recognizerCollection;

@end

NS_ASSUME_NONNULL_END
