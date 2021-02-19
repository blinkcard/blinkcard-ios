//
//  MBCombinedRecognizer.h
//  MicroblinkDev
//
//  Created by DoDo on 17/05/2018.
//

#ifndef MBCombinedRecognizer_h
#define MBCombinedRecognizer_h

@protocol MBCCombinedRecognizerResult;
@class MBCRecognizerResult;

@protocol MBCCombinedRecognizer

@required

/**
 * Combined result which is associated with this combined recognizer.
 */
@property (nonatomic, readonly) MBCRecognizerResult<MBCCombinedRecognizerResult>* combinedResult;

@end

#endif /* MBCombinedRecognizer_h */
