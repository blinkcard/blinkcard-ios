//
//  MBBlinkCardRecognizer.h
//  BlinkShowcaseDev
//
//  Created by Jura Skrlec on 02/11/2020.
//

#import "MBRecognizer.h"
#import "MBBlinkCardRecognizerResult.h"

#import "MBCombinedRecognizer.h"

#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBFullDocumentImageExtensionFactors.h"
#import "MBBlinkCardAnonymizationSettings.h"
#import "MBCheckResult.h"

#import "MBLivenessStatus.h"

@protocol MBCBlinkCardRecognizerDelegate;

NS_ASSUME_NONNULL_BEGIN

/**
 * Recognizer used for scanning credit/debit cards.
 */
MB_CLASS_AVAILABLE_IOS(13.0) MB_FINAL
@interface MBCBlinkCardRecognizer : MBCRecognizer <NSCopying, MBCCombinedRecognizer, MBCFullDocumentImage, MBCEncodeFullDocumentImage, MBCFullDocumentImageDpi, MBCFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning Payment Card Front Recognizer
 */
@property (nonatomic, strong, readonly) MBCBlinkCardRecognizerResult *result;

/**
 * The object that acts as the delegate of the recognizer
 */
@property (nonatomic, nullable, weak) id<MBCBlinkCardRecognizerDelegate> delegate;

/**
 * Should extract the card owner information
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractOwner;

/**
 * Should extract the payment card's month of expiry
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractExpiryDate;

/**
 * Should extract CVV
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractCvv;

/**
 * Should extract the payment card's IBAN
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractIban;

/**
 * Defines whether blured frames filtering is allowed
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL allowBlurFilter;

/**
 * Pading is a minimum distance from the edge of the frame and is defined as a percentage of the frame width. Default value is 0.0f and in that case
 * padding edge and image edge are the same.
 * Recommended value is 0.02f.
 *
 * Default: 0.0f
 */
@property (nonatomic, assign) CGFloat paddingEdge;

/**
 * Defines whether sensitive data should be redacted from the result.
 *
 * Default: See MBCBlinkCardAnonymizationSettings for default settings
 */
@property (nonatomic, strong) MBCBlinkCardAnonymizationSettings *anonymizationSettings;

/**
 * Hand scale is calculated as a ratio between area of hand mask and document mask.
 *
 * Default: 0.15
 */
@property (nonatomic, assign) CGFloat handScaleThreshold;

/**
 * This parameter is used to adjust heuristics that eliminate cases when the hand is present.
 *
 * Default: 0.05
 */
@property (nonatomic, assign) CGFloat handDocumentOverlapThreshold;

/**
 * Screen analysis match level - higher if stricter.
 *
 * Default: Level5
 */
@property (nonatomic) MBCMatchLevel screenAnalysisMatchLevel;

/**
 * Photocopy analysis match level - higher if stricter.
 *
 * Default: Level5
 */
@property (nonatomic) MBCMatchLevel photocopyAnalysisMatchLevel;

/**
 * Whether invalid card number is accepted.
 *
 *Default: NO
 */
@property (nonatomic) BOOL allowInvalidCardNumber;

@end

@protocol MBCBlinkCardRecognizerDelegate <NSObject>

/**
 * Called when liveness status is available
*/
- (void)livenessStatusCallback:(MBCLivenessStatus)livenessStatus;

@end

NS_ASSUME_NONNULL_END
