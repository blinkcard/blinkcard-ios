// Created by Toni Krešo on 26.07.2023.. 
// Copyright (c) 2023 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION 
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS, 
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING 
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED! 
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT 
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#ifndef MBCheckResult_h
#define MBCheckResult_h

typedef NS_ENUM(NSInteger, MBCCheckResult) {
    MBCCheckResultNotPerformed = 0,
    MBCCheckResultPass,
    MBCCheckResultFail
};

typedef NS_ENUM(NSInteger, MBCMatchLevel) {
    MBCMatchLevelDisabled = 0,
    MBCMatchLevel1,
    MBCMatchLevel2,
    MBCMatchLevel3,
    MBCMatchLevel4,
    MBCMatchLevel5,
    MBCMatchLevel6,
    MBCMatchLevel7,
    MBCMatchLevel8,
    MBCMatchLevel9,
    MBCMatchLevel10,
};

#endif /* MBCheckResult_h */
