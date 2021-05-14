// 
// MBRecognizerRunnerViewControllerMetadataDelegates.h
// 
// AUTOMATICALLY GENERATED SOURCE. DO NOT EDIT!
// 
 
#import "MBDebugRecognizerRunnerViewControllerDelegate.h"
#import "MBDetectionRecognizerRunnerViewControllerDelegate.h"
#import "MBOcrRecognizerRunnerViewControllerDelegate.h"
#import "MBGlareRecognizerRunnerViewControllerDelegate.h"
#import "MBFirstSideFinishedRecognizerRunnerViewControllerDelegate.h"
 
#import "MBMicroblinkDefines.h"
#import <Foundation/Foundation.h>
 
/**
 * Class containing all metadata delegates
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBCRecognizerRunnerViewControllerMetadataDelegates : NSObject
 
@property (nonatomic, weak, nullable) id<MBCDebugRecognizerRunnerViewControllerDelegate> debugRecognizerRunnerViewControllerDelegate;
@property (nonatomic, weak, nullable) id<MBCDetectionRecognizerRunnerViewControllerDelegate> detectionRecognizerRunnerViewControllerDelegate;
@property (nonatomic, weak, nullable) id<MBCOcrRecognizerRunnerViewControllerDelegate> ocrRecognizerRunnerViewControllerDelegate;
@property (nonatomic, weak, nullable) id<MBCGlareRecognizerRunnerViewControllerDelegate> glareRecognizerRunnerViewControllerDelegate;
@property (nonatomic, weak, nullable) id<MBCFirstSideFinishedRecognizerRunnerViewControllerDelegate> firstSideFinishedRecognizerRunnerViewControllerDelegate;
 
@end
 