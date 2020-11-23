//
//  MBBlinkCardEditViewController.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 16/10/2020.
//

#import <UIKit/UIKit.h>
#import "MBMicroblinkDefines.h"
#import "MBBlinkCardEditResult.h"
#import "MBBlinkCardRecognizerResult.h"
#import "MBBlinkCardEditFieldConfiguration.h"

@protocol MBCBlinkCardEditViewControllerDelegate;

NS_ASSUME_NONNULL_BEGIN

MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBCBlinkCardEditViewController : UIViewController

MB_INIT_UNAVAILABLE

/**
 * Init view controller with empty MBCBlinkCardResult and default MBCBlinkCardEditFieldConfiguration
 */
- (instancetype)initWithDelegate:(nonnull id<MBCBlinkCardEditViewControllerDelegate>)delegate;

/**
 * Init view controller with MBCBlinkCardResult and custom MBCBlinkCardEditFieldConfiguration
 */
- (instancetype)initWithBlinkCardRecognizerResult:(nullable MBCBlinkCardRecognizerResult *)result
                               fieldConfiguration:(MBCBlinkCardEditFieldConfiguration *)fieldConfiguration
                                         delegate:(nonnull id<MBCBlinkCardEditViewControllerDelegate>)delegate;

/**
 * Delegate
 */
@property (nonatomic, weak) id<MBCBlinkCardEditViewControllerDelegate> delegate;

@end

@protocol MBCBlinkCardEditViewControllerDelegate <NSObject>

/**
 * Called when confirm button is pressed, user has finished editing
 *
 *  @param blinkCardEditViewController Edit view controller responsible for editing
 *  @param editResult Blink Card Edited results
 */
- (void)blinkCardEditViewControllerDidFinishEditing:(nonnull MBCBlinkCardEditViewController *)blinkCardEditViewController
                                         editResult:(nonnull MBCBlinkCardEditResult *)editResult;

/**
 * Edit view controller was closed, usually by the user pressing close button and cancelling the scan
 *
 *  @param blinkCardEditViewController Edit view controller responsible for editing
 */
- (void)blinkCardEditViewControllerDidTapClose:(nonnull MBCBlinkCardEditViewController *)blinkCardEditViewController;

@end

NS_ASSUME_NONNULL_END
