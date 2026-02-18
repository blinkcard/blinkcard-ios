//  Created by Jura Skrlec on 19.02.2025..
//  Modifications are allowed under the terms of the license for files located in the UX/UI lib folder.

import AVFoundation

#if canImport(BlinkIDVerify)
import BlinkIDVerify
#elseif canImport(BlinkID)
import BlinkID
#elseif canImport(BlinkCard)
import BlinkCard
#endif

extension AVCaptureVideoOrientation {
    public func toCameraFrameVideoOrientation() -> CameraFrameVideoOrientation {
        switch self {
            case .portrait: return .portrait
            case .portraitUpsideDown: return .portraitUpsideDown
            case .landscapeLeft: return .landscapeLeft
            case .landscapeRight: return .landscapeRight
            @unknown default: return .portrait
        }
    }

    public static func fromCameraFrameVideoOrientation(_ orientation: CameraFrameVideoOrientation) -> AVCaptureVideoOrientation {
        switch orientation {
            case .portrait: return .portrait
            case .portraitUpsideDown: return .portraitUpsideDown
            case .landscapeLeft: return .landscapeLeft
            case .landscapeRight: return .landscapeRight
            @unknown default: return .portrait
        }
    }
}
