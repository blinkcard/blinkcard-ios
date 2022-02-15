//
//  MBEncodedCombinedFullDocumentImageResult.h
//  MicroblinkDev
//
//  Created by DoDo on 17/05/2018.
//

#ifndef MBEncodedCombinedFullDocumentImageResult_h
#define MBEncodedCombinedFullDocumentImageResult_h

@protocol MBCEncodedCombinedFullDocumentImageResult

@required

/**
 * JPEG-encoded full document image of the front side of the document. Available only if enabled with `MBCEncodeFullDocumentImage encodeFullDocumentImage` property.
 */
@property (nonatomic, readonly, nullable) NSData* encodedFullDocumentFrontImage;

/**
 * JPEG-encoded full document image of the back side of the document. Available only if enabled with `MBCEncodeFullDocumentImage encodeFullDocumentImage` property.
 */
@property (nonatomic, readonly, nullable) NSData* encodedFullDocumentBackImage;

@end

#endif /* MBEncodedCombinedFullDocumentImageResult_h */
