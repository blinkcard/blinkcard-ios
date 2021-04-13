//
//  MBFullDocumentImageResult.h
//  MicroblinkDev
//
//  Created by DoDo on 16/04/2018.
//

#ifndef MBFullDocumentImageResult_h
#define MBFullDocumentImageResult_h

#import "MBImage.h"

@protocol MBCFullDocumentImageResult

@required

/**
 * full document image if enabled with `MBCFullDocumentImage returnFullDocumentImage` property.
 */
@property (nonatomic, readonly, nullable) MBCImage* fullDocumentImage;

@end

#endif /* MBFullDocumentImageResult_h */
