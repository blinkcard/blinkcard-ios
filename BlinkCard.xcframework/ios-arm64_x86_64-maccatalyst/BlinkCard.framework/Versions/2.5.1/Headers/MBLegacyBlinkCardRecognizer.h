//
//  MBBlinkCardRecognizerResult.h
//  MicroblinkDev
//
//  Created by juraskrlec on 29/08/2018.
//

#import "MBRecognizer.h"
#import "MBLegacyBlinkCardRecognizerResult.h"

#import "MBCombinedRecognizer.h"

#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBGlareDetection.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Recognizer used for scanning the front side of credit/debit cards.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_CLASS_DEPRECATED("Use MBCBlinkCardRecognizer") MB_FINAL
@interface MBCLegacyBlinkCardRecognizer : MBCRecognizer <NSCopying, MBCCombinedRecognizer, MBCFullDocumentImage, MBCEncodeFullDocumentImage, MBCFullDocumentImageDpi, MBCGlareDetection, MBCFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning Payment Card Front Recognizer
 */
@property (nonatomic, strong, readonly) MBCLegacyBlinkCardRecognizerResult *result;

/**
 * Should extract the card owner information
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL extractOwner;

/**
 * Should extract the payment card's month of expiry
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractValidThru;

/**
 * Should extract CVV
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractCvv;

/**
 * Should extract the payment card's IBAN
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL extractIban;

/**
 * Should extract the card's inventory number
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractInventoryNumber;

/**
 * Should anonymize the card number area (redact image pixels) on the document image result
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL anonymizeCardNumber;

/**
 * Should anonymize the owner area (redact image pixels) on the document image result
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL anonymizeOwner;

/**
 * Should anonymize the CVV on the document image result
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL anonymizeCvv;

/**
 * Should anonymize the IBAN area (redact image pixels) on the document image result
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL anonymizeIban;

@end

NS_ASSUME_NONNULL_END
