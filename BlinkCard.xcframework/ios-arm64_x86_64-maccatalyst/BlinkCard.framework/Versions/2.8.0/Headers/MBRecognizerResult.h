//
//  MBRecognizerResult.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 22/11/2017.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"

/**
 * Enumeration of posibble recognizer result state
 */
typedef NS_ENUM(NSInteger, MBCRecognizerResultState) {
    
    /**
     *  Empty
     */
    MBCRecognizerResultStateEmpty,
    
    /**
     *  Uncertain
     */
    MBCRecognizerResultStateUncertain,
    
    /**
     *  Valid
     */
    MBCRecognizerResultStateValid,

    /**
     *  StageValid
     */
    MBCRecognizerResultStateStageValid,

};

NS_ASSUME_NONNULL_BEGIN

/**
 * Base class for all recognizer results
 */
MB_CLASS_AVAILABLE_IOS(13.0)
@interface MBCRecognizerResult : NSObject

MB_INIT_UNAVAILABLE

@property (nonatomic, assign, readonly) MBCRecognizerResultState resultState;
@property (nonatomic, readonly) NSString *resultStateString;

@end

NS_ASSUME_NONNULL_END
