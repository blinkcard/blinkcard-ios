//
//  MBDocumentSubview.h
//  MicroBlinkDev
//
//  Created by Jura on 03/02/2019.
//

#import "MBSubview.h"

@protocol MBCRectDocumentSubviewDelegate;

typedef NS_ENUM(NSInteger, MBCRectDocumentSubviewScanMode) {
    MBCRectDocumentSubviewScanModeInitalized,
    MBCRectDocumentSubviewScanModeScanning,
    MBCRectDocumentSubviewScanModeFirstSideScanWillFinish,
    MBCRectDocumentSubviewScanModeWillErrorCameraTooNear,
    MBCRectDocumentSubviewScanModeDidCameraTooNear,
    MBCRectDocumentSubviewScanModeWillErrorCameraTooFar,
    MBCRectDocumentSubviewScanModeDidErrorCameraTooFar,
    MBCRectDocumentSubviewScanModeWillErrorFieldIdentificationFailed,
    MBCRectDocumentSubviewScanModeDidErrorFieldIdentificationFailed,
    MBCRectDocumentSubviewScanModeScanFinished
};

NS_ASSUME_NONNULL_BEGIN

/**
 * Overlay subview presenting the document for scanning
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBCRectDocumentSubview : MBCSubview

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

- (instancetype)initWithFrame:(CGRect)frame NS_DESIGNATED_INITIALIZER;

@property (nonatomic) CGFloat widthToHightAspectRatio;

@property (nonatomic) NSString *titleText;

@property (nonatomic) UILabel *titleView;

@property (nonatomic) CGSize viewSize;

@property (nonatomic) CGFloat titleTextDelay;

@property (nonatomic) UIView *centerView;

@property (nonatomic, weak, nullable) id<MBCRectDocumentSubviewDelegate> rectSubviewDelegate;

- (void)startScanLineAnimation;

- (void)stopScanLineAnimation;

- (void)startFlipAnimation;

- (void)updateForMode:(MBCRectDocumentSubviewScanMode)mode;

- (void)startScannedFirstSideFinishAnimation;

- (void)resetTitleLabelConstraint;

- (void)configureCornersBounds;

- (void)updateProgress;

@end

@protocol MBCRectDocumentSubviewDelegate <NSObject>

- (void)rectDocumentSubviewDidFinishFlipAnimation:(nonnull MBCRectDocumentSubview *)rectDocumentSubvie;

- (void)rectDocumentSubviewDidFinishAnimation:(nonnull MBCRectDocumentSubview *)rectDocumentSubvie;

- (void)rectDocumentSubviewDidStartTransitionAnimation:(nonnull MBCRectDocumentSubview *)rectDocumentSubvie mode:(MBCRectDocumentSubviewScanMode)mode;

@end

NS_ASSUME_NONNULL_END
