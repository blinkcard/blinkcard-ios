//
//  MBBlinkCardEditResult.h
//  BlinkShowcaseDev
//
//  Created by Jura Skrlec on 26/10/2020.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

MB_CLASS_AVAILABLE_IOS(9.0) MB_FINAL
@interface MBCBlinkCardEditResult : NSObject<NSCopying>

/**
 * Blink Card edit card number
 *
 * Default: nil
 */
@property(nonatomic, strong, nullable) NSString *cardNumber;

/**
 * Blink Card edit card owner
 *
 * Default: nil
 */
@property(nonatomic, strong, nullable) NSString *owner;

/**
 * Blink Card edit card security code
 *
 * Default: nil
 */
@property(nonatomic, strong, nullable) NSString *cvv;

/**
 * Blink Card edit card ecpiry date
 *
 * Default: nil
 */
@property(nonatomic, strong, nullable) NSString *expiryDate;

/**
 * Blink Card edit card iban
 *
 * Default: nil
 */
@property(nonatomic, strong, nullable) NSString *iban;

@end

NS_ASSUME_NONNULL_END
