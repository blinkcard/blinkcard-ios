//
//  MBCombinedRecognizerResult.h
//  MicroblinkDev
//
//  Created by DoDo on 17/05/2018.
//

#ifndef MBCombinedRecognizerResult_h
#define MBCombinedRecognizerResult_h

/**
* Result of the data matching algorithm for scanned parts/sides of the document.
**/
typedef NS_ENUM(NSInteger, MBCDataMatchResult) {
    /** Data matching has not been performed. */
    MBCDataMatchResultNotPerformed = 0,
    /** Data does not match. */
    MBCDataMatchResultFailed,
    /** Data match. */
    MBCDataMatchResultSuccess
};

@protocol MBCCombinedRecognizerResult

@required

/**
 * Returns YES if recognizer has finished scanning first side and is now scanning back side,
 * NO if it's still scanning first side.
 */
@property (nonatomic, readonly, assign) BOOL scanningFirstSideDone;

@optional
/**
 * Returns MBCDataMatchResultSuccess if data from scanned parts/sides of the document match,
 * MBCDataMatchResultFailed otherwise. For example if date of expiry is scanned from the front and back side
 * of the document and values do not match, this method will return MBCDataMatchResultFailed. Result will
 * be MBCDataMatchResultSuccess only if scanned values for all fields that are compared are the same.
 */
@property (nonatomic, readonly, assign) MBCDataMatchResult documentDataMatch;

@end

#endif /* MBCombinedRecognizerResult_h */
