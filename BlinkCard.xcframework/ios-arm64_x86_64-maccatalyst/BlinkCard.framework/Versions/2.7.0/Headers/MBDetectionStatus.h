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
    
    /** Object was not detected */
    MBCDetectionStatusFail,
    
    /** Object was successfuly detected. */
    MBCDetectionStatusSuccess,
    
    /** Object was successfully detected, but the camera was too far above the object for processing */
    MBCDetectionStatusCameraTooHigh,
    
    /** Object was successfully detected using a fallback algorithm */
    MBCDetectionStatusFallbackSuccess,
    
    /** Object was detected, but is only partially visible on screen */
    MBCDetectionStatusPartialForm,

    /** Object was successfully detected, but the perspective angle of camera is too high */
    MBCDetectionStatusCameraAtAngle,
    
    /** Object was successfully detected, but the camera is too near to the object for processing */
    MBCDetectionStatusCameraTooNear,
    
    /** Document detected, but document is too close to the edge of the frame */
    MBCDetectionStatusDocumentTooCloseToEdge,
};
