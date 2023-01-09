//
//  MBBlinkCardRecognizerResult.h
//  BlinkShowcaseDev
//
//  Created by Jura Skrlec on 02/11/2020.
//

#import "MBRecognizerResult.h"
#import "MBDate.h"

#import "MBCombinedRecognizerResult.h"
#import "MBCombinedFullDocumentImageResult.h"
#import "MBEncodedCombinedFullDocumentImageResult.h"

#import "MBIssuer.h"
#import "MBBlinkCardProcessingStatus.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning credit/debit cards
 */
MB_CLASS_AVAILABLE_IOS(13.0)
@interface MBCBlinkCardRecognizerResult : MBCRecognizerResult<NSCopying, MBCCombinedRecognizerResult>

MB_INIT_UNAVAILABLE

/**
 * Payment card's issuing network.
 */
@property (nonatomic, readonly) MBCIssuer issuer;

/**
 * The payment card number.
 */
@property (nonatomic, readonly) NSString *cardNumber;

/**
 * The payment card number is valid
 */
@property (nonatomic, readonly) BOOL cardNumberValid;

/**
 * The payment card number prefix.
 */
@property (nonatomic, readonly) NSString *cardNumberPrefix;

/**
 * Payment card's IBAN.
 */
@property (nonatomic, readonly) NSString *iban;

/**
 *  Payment card's security code/value.
 */
@property (nonatomic, readonly) NSString *cvv;

/**
 * The payment card's expiry date.
 */
@property (nonatomic, readonly) MBCDate *expiryDate;

/**
 * Information about the payment card owner (name, company, etc.).
 */
@property (nonatomic, readonly) NSString *owner;

/**
 * Wheater the first scanned side is blurred.
 */
@property (nonatomic, readonly) BOOL firstSideBlurred;

/**
 * Wheater the second scanned side is blurred.
 */
@property (nonatomic, readonly) BOOL secondSideBlurred;

/**
 * Full image of the payment card from first side recognition.
 */
@property (nonatomic, readonly, nullable) MBCImage *firstSideFullDocumentImage;

/**
 * Full image of the payment card from second side recognition.
 */
@property (nonatomic, readonly, nullable) MBCImage *secondSideFullDocumentImage;

/**
 * JPEG-encoded full document image of the first side of the payment card. Available only if enabled with `MBCEncodeFullDocumentImage encodeFullDocumentImage` property.
 */
@property (nonatomic, readonly, nullable) NSData *encodedFirstSideFullDocumentImage;

/**
 * JPEG-encoded full document image of the second side of the payment card. Available only if enabled with `MBCEncodeFullDocumentImage encodeFullDocumentImage` property.
 */
@property (nonatomic, readonly, nullable) NSData *encodedSecondSideFullDocumentImage;

/**
 * Status of the last recognition process.
 */
@property (nonatomic, readonly) MBCBlinkCardProcessingStatus processingStatus;

@end

NS_ASSUME_NONNULL_END
