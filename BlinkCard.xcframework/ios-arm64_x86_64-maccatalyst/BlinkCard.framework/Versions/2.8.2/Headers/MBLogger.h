//
//  MBLogger.h
//  PhotoMathFramework
//
//  Created by Marko Mihovilić on 23/03/16.
//  Copyright © 2016 Microblink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MBMicroblinkDefines.h"

typedef NS_ENUM(NSInteger, MBCLogLevel) {
    MBCLogLevelError,
    MBCLogLevelWarning,
    MBCLogLevelInfo,
    MBCLogLevelDebug,
    MBCLogLevelVerbose
};

@protocol MBCLoggerDelegate <NSObject>

@optional

- (void)log:(MBCLogLevel)level message:(const char *)message;
- (void)log:(MBCLogLevel)level format:(const char *)format arguments:(const char *)arguments;

@end

MB_CLASS_AVAILABLE_IOS(13.0) @interface MBCLogger : NSObject

@property (nonatomic) id<MBCLoggerDelegate> delegate;

+ (instancetype)sharedInstance NS_SWIFT_NAME(shared());

- (void)disableMicroblinkLogging;

@end
