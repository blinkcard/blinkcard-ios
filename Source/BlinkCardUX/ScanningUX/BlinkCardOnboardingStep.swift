//  Created by Toni Krešo on 13.02.2026..
//  Copyright (c) Microblink. All rights reserved.
//  Modifications are allowed under the terms of the license for files located in the UX/UI lib folder.

import SwiftUI

enum BlinkCardOnboardingStep: Int, OnboardingStepProtocol {
    case cardNumber, allFieldsVisible, harshLight, keepStill
    
    var id: Int { rawValue }
    
    var image: Image {
        switch self {
        case .cardNumber:
            return Image.cardNumberImage
        case .allFieldsVisible:
            return Image.allCardFieldsVisibleImage
        case .harshLight:
            return Image.harshLightCardImage
        case .keepStill:
            return Image.keepCardStillImage
        }
    }
    
    var title: String {
        switch self {
        case .cardNumber:
            return "mb_blinkcard_help_screen_title1"
        case .allFieldsVisible:
            return "mb_blinkcard_help_screen_title2"
        case .harshLight:
            return "mb_blinkcard_help_screen_title3"
        case .keepStill:
            return "mb_blinkcard_help_screen_title4"
        }
    }
    
    var description: String {
        switch self {
        case .cardNumber:
            return "mb_blinkcard_help_screen_msg1"
        case .allFieldsVisible:
            return "mb_blinkcard_help_screen_msg2"
        case .harshLight:
            return "mb_blinkcard_help_screen_msg3"
        case .keepStill:
            return "mb_blinkcard_help_screen_msg4"
        }
    }
}
