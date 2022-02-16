//
//  MBBlinkCardProcessingStatus.h
//  BlinkShowcaseDev
//
//  Created by Jura Skrlec on 02/11/2020.
//

#ifndef MBBlinkCardProcessingStatus_h
#define MBBlinkCardProcessingStatus_h

/**
* MBCBlinkCardProcessingStatus enum defines status of the last recognition process.
*/
typedef NS_ENUM(NSInteger, MBCBlinkCardProcessingStatus) {

    /** Recognition was successful. */
    MBCBlinkCardProcessingStatusSuccess,

    /** Detection of the document failed. */
    MBCBlinkCardProcessingStatusDetectionFailed,

    /** Preprocessing of the input image has failed. */
    MBCBlinkCardProcessingStatusImagePreprocessingFailed,

    /** Recognizer has inconsistent results. */
    MBCBlinkCardProcessingStatusStabilityTestFailed,

    /** Wrong side of the document has been scanned. */
    MBCBlinkCardProcessingStatusScanningWrongSide,

    /** Identification of the fields present on the document has failed. */
    MBCBlinkCardProcessingStatusFieldIdentificationFailed,

    /** Failed to return a requested image. */
    MBCBlinkCardProcessingStatusImageReturnFailed,

    /** Payment card currently not supported by the recognizer. */
    MBCBlinkCardProcessingStatusUnsupportedCard
};

#endif /* MBBlinkCardProcessingStatus_h */
