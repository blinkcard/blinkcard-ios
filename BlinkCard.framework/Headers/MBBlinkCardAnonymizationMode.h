// Created by Jura Skrlec on 25.03.2021..
// Copyright (c) 2021 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#ifndef MBBlinkCardAnonymizationMode_h
#define MBBlinkCardAnonymizationMode_h

/**
 * Determines which data is anonymized in the returned recognizer result.
 */
typedef NS_ENUM(NSInteger, MBCBlinkCardAnonymizationMode) {

    /**
     * No anonymization is performed in this mode.
     */
    MBCBlinkCardAnonymizationModeNone = 0,

    /**
     * Sensitive data in the document image is anonymized with black boxes covering selected sensitive data. Data returned in result fields is not changed.
     */
    MBCBlinkCardAnonymizationModeImageOnly,

    /**
     * Document image is not changed. Data returned in result fields is redacted.
     */
    MBCBlinkCardAnonymizationModeResultFieldsOnly,

    /**
     * Sensitive data in the image is anonymized with black boxes covering selected sensitive data. Data returned in result fields is redacted.
     */
    MBCBlinkCardAnonymizationModeFullResult
};


#endif /* MBBlinkCardAnonymizationMode_h */
