//  Created by Toni Kreso on 13.01.2026..
//  Copyright (c) Microblink. All rights reserved.
//  This code is provided for use as-is and may not be copied, modified, or redistributed.
//

import BlinkCard

public enum BlinkCardUIEvent: Equatable, Sendable {
    /// Request to scan the second side of the card
    case requestSecondSide
    
    /// Camera image is too blurry for accurate card detection
    case blur
    
    /// A field marked as mandatory was not extracted from the card
    case fieldIdentificationFailed
    
    /// Card is partially outside the camera frame
    case notFullyVisible
    
    /// Card is not parallel to the camera plane
    case tilt
    
    /// Card is too close to the camera
    case tooClose
    
    /// Card is positioned too close to the screen edges
    case tooCloseToEdge
    
    /// Card is too far from the camera
    case tooFar
    
    /// Indicates the wrong side of the card is being presented
    case wrongSide
    
    /// Failed to return a requested image.
    case imageReturnFailed
}
