//
//  MBBlinkCardEditFieldConfiguration.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 20/10/2020.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBCBlinkCardEditFieldConfiguration : NSObject<NSCopying>

/**
 * Defines whether card number should be displayed
 *
 * Default: YES
*/
@property(nonatomic, assign) BOOL shouldDisplayCardNumber;

/**
 * Defines whether card owner should be displayed
 *
 * Default: YES
*/
@property(nonatomic, assign) BOOL shouldDisplayOwner;

/**
 * Defines whether card CVV  should be displayed
 *
 * Default: YES
*/
@property(nonatomic, assign) BOOL shouldDisplayCvv;

/**
 * Defines whether card date of expiry should be displayed
 *
 * Default: YES
*/
@property(nonatomic, assign) BOOL shouldDisplayExpiryDate;

/**
 * Defines whether card IBAN should be displayed
 *
 * Default: NO
*/
@property(nonatomic, assign) BOOL shouldDisplayIban;


/**
 * Disable popup that blocks user when tapping “Add” button if card fields have any validation errors.
 *
 * Default: NO
 */
@property(nonatomic, assign) BOOL allowCardsWithInvalidFields;

@end

NS_ASSUME_NONNULL_END
