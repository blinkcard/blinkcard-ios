//
//  MBCombinedRecognizerResult.h
//  MicroblinkDev
//
//  Created by DoDo on 17/05/2018.
//

#ifndef MBCombinedRecognizerResult_h
#define MBCombinedRecognizerResult_h

#import "MBDataMatchState.h"

@protocol MBCCombinedRecognizerResult

@required

/**
 * Returns YES if recognizer has finished scanning first side and is now scanning back side,
 * NO if it's still scanning first side.
 */
@property (nonatomic, readonly, assign) BOOL scanningFirstSideDone;

@optional
/**
 * Returns MBCDataMatchStateSuccess if data from scanned parts/sides of the document match,
 * MBCDataMatchStateFailed otherwise. For example if date of expiry is scanned from the front and back side
 * of the document and values do not match, this method will return MBCDataMatchStateFailed. Result will
 * be MBCDataMatchStateSuccess only if scanned values for all fields that are compared are the same.
 */
@property (nonatomic, readonly, assign) MBCDataMatchState documentDataMatch;

@end

#endif /* MBCombinedRecognizerResult_h */
