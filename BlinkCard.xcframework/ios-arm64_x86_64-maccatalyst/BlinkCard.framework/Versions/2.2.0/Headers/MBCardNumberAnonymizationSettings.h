// Created by Jura Skrlec on 25.03.2021..
// Copyright (c) 2021 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBBlinkCardAnonymizationMode.h"

NS_ASSUME_NONNULL_BEGIN
/**
 * Holds the settings which control card number anonymization.
 */
MB_CLASS_AVAILABLE_IOS(9.0) MB_FINAL
@interface MBCCardNumberAnonymizationSettings : NSObject<NSCopying>

MB_INIT

/**
 * Defines the mode of card number anonymization.
 *
 * Default: MBCBlinkCardAnonymizationModeNone
 */
@property(nonatomic, assign) MBCBlinkCardAnonymizationMode mode;

/**
 * Defines how many digits at the beginning of the card number remain visible after anonymization.
 *
 * Default: 0
 */
@property(nonatomic, assign) NSInteger prefixDigitsVisible;

/**
 * Defines how many digits at the end of the card number remain visible after anonymization.
 *
 * Default: 0
 */
@property(nonatomic, assign) NSInteger suffixDigitsVisible;

@end

NS_ASSUME_NONNULL_END
