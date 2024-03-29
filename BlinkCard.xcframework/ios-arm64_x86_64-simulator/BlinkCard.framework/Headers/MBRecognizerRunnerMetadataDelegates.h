// 
// MBRecognizerRunnerMetadataDelegates.h
// 
// AUTOMATICALLY GENERATED SOURCE. DO NOT EDIT!
// 
 
#import "MBDebugRecognizerRunnerDelegate.h"
#import "MBDetectionRecognizerRunnerDelegate.h"
#import "MBOcrRecognizerRunnerDelegate.h"
#import "MBGlareRecognizerRunnerDelegate.h"
#import "MBFirstSideFinishedRecognizerRunnerDelegate.h"
 
#import "MBMicroblinkDefines.h"
#import <Foundation/Foundation.h>
 
/**
 * Class containing all metadata delegates
 */
MB_CLASS_AVAILABLE_IOS(13.0) MB_FINAL
@interface MBCRecognizerRunnerMetadataDelegates : NSObject
 
@property (nonatomic, weak, nullable) id<MBCDebugRecognizerRunnerDelegate> debugRecognizerRunnerDelegate;
@property (nonatomic, weak, nullable) id<MBCDetectionRecognizerRunnerDelegate> detectionRecognizerRunnerDelegate;
@property (nonatomic, weak, nullable) id<MBCOcrRecognizerRunnerDelegate> ocrRecognizerRunnerDelegate;
@property (nonatomic, weak, nullable) id<MBCGlareRecognizerRunnerDelegate> glareRecognizerRunnerDelegate;
@property (nonatomic, weak, nullable) id<MBCFirstSideFinishedRecognizerRunnerDelegate> firstSideFinishedRecognizerRunnerDelegate;
 
@end
 