//
//  MBBlinkCardRecognizerResult.h
//  MicroBlinkDev
//
//  Created by juraskrlec on 29/08/2018.
//

#import "MBRecognizerResult.h"
#import "MBDate.h"

#import "MBCombinedRecognizerResult.h"
#import "MBCombinedFullDocumentImageResult.h"
#import "MBEncodedCombinedFullDocumentImageResult.h"

#import "MBLegacyCardIssuer.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning front side of the Payment Card
 */
MB_CLASS_AVAILABLE_IOS(13.0) MB_CLASS_DEPRECATED("Use MBCBlinkCardRecognizerResult")
@interface MBCLegacyBlinkCardRecognizerResult : MBCRecognizerResult<NSCopying, MBCCombinedRecognizerResult, MBCCombinedFullDocumentImageResult, MBCEncodedCombinedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The payment card number.
 */
@property (nonatomic, readonly) NSString *cardNumber;

/**
 * Information about the payment card owner (name, company, etc.).
 */
@property (nonatomic, readonly) NSString *owner;

/**
 * The payment card's last month of validity.
 */
@property (nonatomic, readonly) MBCDate *validThru;

/**
 *  Payment card's security code/value
 */
@property (nonatomic, readonly) NSString *cvv;

/**
 * Payment card's inventory number.
 */
@property (nonatomic, readonly) NSString *inventoryNumber;

/**
 * Payment card's issuing network
 */
@property (nonatomic, readonly) MBCLegacyCardIssuer issuer;

/**
 * Payment card's IBAN
 */
@property (nonatomic, readonly) NSString *iban;

@end

NS_ASSUME_NONNULL_END
