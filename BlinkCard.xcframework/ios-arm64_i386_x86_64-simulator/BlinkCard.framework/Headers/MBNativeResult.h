//
//  PPResult.h
//  BlinkIdFramework
//
//  Created by DoDo on 07/11/2016.
//  Copyright © 2016 Microblink Ltd. All rights reserved.
//

#ifndef PPResult_h
#define PPResult_h

#import "Foundation/Foundation.h"

@protocol MBCNativeResult

/**
 * Returns the native object containing the result. For example, for MBCDateResult, this method
 * will return NSDate object.
 */
- (NSObject *_Nullable)nativeResult;

/**
 * Returns the string version of the result. For example, for MBCDateResult, this method
 * will return original string from which date was parsed (same as MBCDateResult's originalDateString property}.
 */
- (NSString *_Nullable)stringResult;

@end

#endif /* PPResult_h */
