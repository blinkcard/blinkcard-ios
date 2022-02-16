//
//  MBDetectionStatus.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 08/12/2017.
//

/**
 * Status of the object detection in Microblink SDK
 */
typedef NS_OPTIONS(NSInteger, MBCDetectionStatus) {
    
    /** Object was successfuly detected. */
    MBCDetectionStatusSuccess = 1 << 0,
    
    /** Object was not detected */
    MBCDetectionStatusFail = 1 << 1,
    
    /** Object was successfully detected, but the camera was too far above the object for processing */
    MBCDetectionStatusCameraTooHigh = 1 << 2,
    
    /** Object was successfully detected, but the perspective angle of camera is too high */
    MBCDetectionStatusCameraAtAngle = 1 << 3,
    
    /** Object was successfully detected, but the object is rotated and not aligned to the camera edges */
    MBCDetectionStatusCameraRotated = 1 << 4,
    
    /** QR code was successfully detected */
    MBCDetectionStatusQRSuccess = 1 << 6,
    
    /** PDF417 barcode was successfully detected */
    MBCDetectionStatusPdf417Success = 1 << 7,
    
    /** Object was successfully detected using a fallback algorithm */
    MBCDetectionStatusFallbackSuccess = 1 << 8,
    
    /** Object was detected, but is only partially visible on screen */
    MBCDetectionStatusPartialForm = 1 << 9,
    
    /** Object was successfully detected, but the camera is too near to the object for processing */
    MBCDetectionStatusCameraTooNear = 1 << 10,
    
    /** Document detected, but document is too close to the edge of the frame */
    MBCDetectionStatusDocumentTooCloseToEdge = 1 << 11,
};
