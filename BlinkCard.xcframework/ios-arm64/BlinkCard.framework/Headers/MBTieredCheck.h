// Created by Toni Krešo on 26.07.2023.. 
// Copyright (c) 2023 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION 
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS, 
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING 
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED! 
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT 
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import "MBCheckResult.h"
#import "MBMicroblinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

MB_CLASS_AVAILABLE_IOS(13.0)
@interface MBCTieredCheck : NSObject

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithResult:(MBCCheckResult)result level:(MBCMatchLevel)level NS_DESIGNATED_INITIALIZER;

@property (nonatomic, readonly) MBCCheckResult result;
@property (nonatomic, readonly) MBCMatchLevel level;

@end

NS_ASSUME_NONNULL_END
