//
//  PPBaseOverlayViewController.h
//  BarcodeFramework
//
//  Created by Jura on 06/06/14.
//  Copyright (c) 2015 Microblink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MBOverlayViewController.h"
#import "MBGeometry.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Common base class for default overlay view controllers
 */
MB_CLASS_AVAILABLE_IOS(13.0)
@interface MBCBaseOverlayViewController : MBCOverlayViewController

/**
 * Reconfigures current recognizer collection to new recognizer collection. Use this method to reconfigure what you wish to scan.
 */
- (void)reconfigureRecognizers:(MBCRecognizerCollection *)recognizerCollection;

@end

NS_ASSUME_NONNULL_END
