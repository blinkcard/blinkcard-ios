//
//  MBBlinkCardUtils.h
//  BlinkShowcaseDev
//
//  Created by Jura Skrlec on 02/11/2020.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBIssuer.h"

NS_ASSUME_NONNULL_BEGIN

MB_CLASS_AVAILABLE_IOS(9.0)
@interface MBCBlinkCardUtils : NSObject

MB_INIT_UNAVAILABLE

/**
 * Determine payment card issuer based on first couple of digits of the payment card number.
 */
+ (MBCIssuer)determineIssuerFromCardNumberPrefix:(NSString *)cardNumberPrefix;

/**
 * Checks wheater the provided cardNumber is valid.
 * Validation is performed by calculating the check digit using Luhn algorithm and comparing it
 * with the last digit of the provided card number.
 */
+ (BOOL)isValidCardNumber:(NSString *)cardNumber;

/**
 * Checks whether the provided iban is valid.
 */
+ (BOOL)isValidIban:(NSString *)iban;

/**
 * Enum MBCIssuer to string helper method
 */
+ (NSString *)issuerToString:(MBCIssuer)issuer;

@end

NS_ASSUME_NONNULL_END
