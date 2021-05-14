//
//  MBOcrLayoutSubview.h
//  MicroblinkDev
//
//  Created by Dino Gustin on 02/05/2018.
//

#import "MBOcrLayout.h"

/**
 * Protocol for processing MBCOcrLayout. Subviews implementing this protocol process and draw layout data on the screen (e.g. dots or OCR characters)
 */
@protocol MBCOcrLayoutSubview <NSObject>

/**
 * This method should be called when MBCOcrLayout is obtained and needs to be drawn/redrawn.
 */
- (void)ocrLayoutObtained:(MBCOcrLayout *)ocrLayout withIdentifier:(NSString *)identifier;

@end
