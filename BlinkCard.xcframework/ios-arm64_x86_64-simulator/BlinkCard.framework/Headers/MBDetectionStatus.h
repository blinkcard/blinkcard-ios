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
    
    /** Detection has failed. */
    MBCDetectionStatusFailed,
    
    /** Document has been detected. */
    MBCDetectionStatusSuccess,
    
    /** Document has been detected but the camera is too far from the document. */
    MBCDetectionStatusCameraTooFar,
    
    /** Document has been detected but the camera is too close to the document. */
    MBCDetectionStatusCameraTooClose,
    
    /** Document has been detected but the camera’s angle is too steep. */
    MBCDetectionStatusCameraAngleTooSteep,
    
    /** Document has been detected but the document is too close to the camera edge. */
    MBCDetectionStatusDocumentTooCloseToCameraEdge,
    
    /** Only part of the document is visible. */
    MBCDetectionStatusDocumentPartiallyVisible,
    
    /** Fallback detection was successful (PhotoPay specific). */
    MBCDetectionStatusFallbackSuccess
};
