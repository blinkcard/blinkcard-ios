//  Created by Toni Krešo on 05.03.2025..
//  Copyright (c) Microblink. All rights reserved.
//  Modifications are allowed under the terms of the license for files located in the UX/UI lib folder.
//

#if BLINKIDVERIFYUX
import BlinkIDVerify
#elseif BLINKIDUX
import BlinkID
#elseif BLINKCARDUX
import BlinkCard
#endif

public protocol AlertTypeProtocol: Identifiable {
    var title: String { get }
    var description: String { get }
    var buttonTitle: String { get }
    var pingletAlertType: UxEventPinglet.AlertType { get }
}
