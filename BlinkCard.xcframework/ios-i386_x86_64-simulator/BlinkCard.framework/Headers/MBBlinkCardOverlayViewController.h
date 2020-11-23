//
//  MBBlinkCardOverlayViewController.h
//  MicroBlinkDev
//
//  Created by Jura on 31/01/2019.
//

#import "MBBaseOverlayViewController.h"
#import "MBBlinkCardOverlaySettings.h"
#import "MBBlinkCardEditResult.h"
#import "MBBlinkCardEditViewController.h"

@protocol MBCBlinkCardOverlayViewControllerDelegate;

NS_ASSUME_NONNULL_BEGIN

/**
 * Settings class containing UI information for BlinkCard
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBCBlinkCardOverlayViewController : MBCBaseOverlayViewController

/**
 * Common settings
 */
@property (nonatomic, strong, readonly) MBCBlinkCardOverlaySettings *settings;

/**
 * Delegate
 */
@property (nonatomic, weak, readonly) id<MBCBlinkCardOverlayViewControllerDelegate> delegate;

/*
 * Editable view controller
 */
@property(nonatomic, strong, nullable) MBCBlinkCardEditViewController *blinkCardEditViewController;

/**
 * Designated intializer.
 *
 *  @param settings MBCBlinkCardOverlaySettings object
 *
 *  @param recognizerCollection MBCRecognizerCollection object
 *
 *  @return initialized overlayViewController
 */
- (instancetype)initWithSettings:(MBCBlinkCardOverlaySettings *)settings
            recognizerCollection:(MBCRecognizerCollection *)recognizerCollection
                        delegate:(nonnull id<MBCBlinkCardOverlayViewControllerDelegate>)delegate;


@end

/**
 * Protocol for obtaining scanning results
 */
@protocol MBCBlinkCardOverlayViewControllerDelegate <NSObject>

@required
/**
 * Scanning library did output scanning results
 *
 * Depending on how you want to treat the result, you might want to
 * dismiss the scanningViewController here.
 *
 * This method is the default way for getting access to results of scanning.
 *
 * Note:
 * - there may be 0, 1, or more than one scanning results.
 * - each scanning result belongs to a common MBCRecognizerResult type
 * - handle different types differently
 *
 *  @param blinkCardOverlayViewController documentOverlayViewController Scanning view controller responsible for scanning
 *  @param state                  state of scanning
 *
 *
 * NOTE: This method is called on background processing thread. Make sure that you dispatch all your UI API calls to main thread.
 */
- (void)blinkCardOverlayViewControllerDidFinishScanning:(nonnull MBCBlinkCardOverlayViewController *)blinkCardOverlayViewController state:(MBCRecognizerResultState)state;

/**
 * Scanning library was closed, usually by the user pressing close button and cancelling the scan
 *
 *  @param blinkCardOverlayViewController Scanning view controller responsible for scanning
 */
- (void)blinkCardOverlayViewControllerDidTapClose:(nonnull MBCBlinkCardOverlayViewController *)blinkCardOverlayViewController;

@optional
/**
 * Called when scanning library finished scanning first side of the document
 *
 *  @param blinkCardOverlayViewController blinkCardOverlayViewController Scanning view controller responsible for scanning
 */
- (void)blinkCardOverlayViewControllerDidFinishScanningFirstSide:(nonnull MBCBlinkCardOverlayViewController *)blinkCardOverlayViewController;

/**
 * Called when scanning library edit screen values are confirmed
 *
 *  @param blinkCardOverlayViewController BlinkCardOverlayViewController Scanning view controller responsible for scanning and showing edit view controller
 */
- (void)blinkCardOverlayViewControllerDidFinishEditing:(nonnull MBCBlinkCardOverlayViewController *)blinkCardOverlayViewController editResult:(MBCBlinkCardEditResult *)editResult;

@end

NS_ASSUME_NONNULL_END
