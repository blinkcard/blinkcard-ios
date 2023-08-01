// Created by Toni Krešo on 26.07.2023.. 
// Copyright (c) 2023 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION 
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS, 
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING 
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED! 
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT 
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import "MBMicroblinkDefines.h"
#import "MBTieredCheck.h"
#import "MBCheckResult.h"

NS_ASSUME_NONNULL_BEGIN

MB_CLASS_AVAILABLE_IOS(13.0)
@interface MBCDocumentLivenessCheckSingleSideResult : NSObject

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithScreenCheck:(MBCTieredCheck *)screenCheck photocopyCheck:(MBCTieredCheck *)photocopyCheck handPresenceCheck:(MBCCheckResult)handPresenceCheck NS_DESIGNATED_INITIALIZER;

@property (nonatomic, readonly) MBCTieredCheck *screenCheck;
@property (nonatomic, readonly) MBCTieredCheck *photocopyCheck;
@property (nonatomic, readonly) MBCCheckResult handPresenceCheck;

@end

MB_CLASS_AVAILABLE_IOS(13.0)
@interface MBCDocumentLivenessCheckResult : NSObject

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithFront:(MBCDocumentLivenessCheckSingleSideResult *)front back:(MBCDocumentLivenessCheckSingleSideResult *)back NS_DESIGNATED_INITIALIZER;

@property (nonatomic, readonly) MBCDocumentLivenessCheckSingleSideResult *front;
@property (nonatomic, readonly) MBCDocumentLivenessCheckSingleSideResult *back;

@end

NS_ASSUME_NONNULL_END

