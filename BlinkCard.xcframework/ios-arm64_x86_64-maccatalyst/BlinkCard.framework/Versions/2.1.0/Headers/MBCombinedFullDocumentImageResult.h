//
//  MBCombinedFullDocumentImageResult.h
//  MicroblinkDev
//
//  Created by DoDo on 17/05/2018.
//

#ifndef MBCombinedFullDocumentImageResult_h
#define MBCombinedFullDocumentImageResult_h

#import "MBImage.h"

@protocol MBCCombinedFullDocumentImageResult

@required

/**
 * front side image of the document if enabled with `MBCFullDocumentImage returnFullDocumentImage` property.
 */
@property (nonatomic, readonly, nullable) MBCImage* fullDocumentFrontImage;

/**
 * back side image of the document if enabled with `MBCFullDocumentImage returnFullDocumentImage` property.
 */
@property (nonatomic, readonly, nullable) MBCImage* fullDocumentBackImage;

@end

#endif /* MBCombinedFullDocumentImageResult_h */
