// Created by Jura Skrlec on 25.03.2021..
// Copyright (c) 2021 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import <Foundation/Foundation.h>
#import "MBCardNumberAnonymizationSettings.h"
#import "MBBlinkCardAnonymizationSettings.h"
#import "MBMicroblinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

MB_CLASS_AVAILABLE_IOS(13.0) MB_FINAL
@interface MBCBlinkCardAnonymizationSettings : NSObject<NSCopying>

MB_INIT

/**
 * Defines the parameters of card number anonymization.
 */
@property(nonatomic, strong) MBCCardNumberAnonymizationSettings *cardNumberAnonymizationSettings;

/**
 * Defines the mode of card number prefix anonymization.
 *
 * Default: MBCBlinkCardAnonymizationModeNone
 */
@property(nonatomic, assign) MBCBlinkCardAnonymizationMode cardNumberPrefixAnonymizationMode;

/**
 * Defines the mode of CVV anonymization.
 *
 * Default: MBCBlinkCardAnonymizationModeNone
 */
@property(nonatomic, assign) MBCBlinkCardAnonymizationMode cvvAnonymizationMode;

/**
 * Defines the mode of IBAN anonymization.
 *
 * Default: MBCBlinkCardAnonymizationModeNone
 */
@property(nonatomic, assign) MBCBlinkCardAnonymizationMode ibanAnonymizationMode;

/**
 * Defines the mode of owner anonymization.
 *
 * Default: MBCBlinkCardAnonymizationModeNone
 */
@property(nonatomic, assign) MBCBlinkCardAnonymizationMode ownerAnonymizationMode;

/**
 * If true, anonymization is applied on all fields of the image if extraction is uncertain.
 *
 * Default: NO
 */
@property(nonatomic, assign)  BOOL fallbackAnonymization;

@end

NS_ASSUME_NONNULL_END
