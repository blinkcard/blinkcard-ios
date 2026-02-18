//  Created by Toni Kreso on 17.12.2025..
//  Copyright (c) Microblink. All rights reserved.
//  Modifications are allowed under the terms of the license for files located in the UX/UI lib folder.

import SwiftUI

public final class BlinkCardTheme: UXThemeProtocol {
    public static let shared = BlinkCardTheme()
    
    private init() {}
    
    // theme for tutorial alert
    // title
    public var alertTitleColor: Color = .mbPrimary
    public var alertTitleFont: Font = .headline
    // description
    public var alertDescriptionColor: Color = .primary
    public var alertDescriptionFont: Font = .footnote
    // button
    public var alertButtonColor: Color = .mbSecondary
    public var alertButtonFont: Font = .headline
    // background
    public var alertBackgroundColor: Color = .mbBackground
    
    // theme for onboarding sheet
    // title
    public var onboardingSheetTitleColor: Color = .mbPrimary
    public var onboardingSheetTitleFont: Font = .title2
    // description
    public var onboardingSheetDescriptionColor: Color = .primary
    public var onboardingSheetDescriptionFont: Font = .subheadline
    // navigation buttons
    public var onboardingSheetButtonColor: Color = .mbSecondary
    public var onboardingSheetButtonFont: Font = .headline
    // indicator
    public var onboardingSheetPageIndicatorColor: Color = .mbSecondary
    // background
    public var onboardingSheetBackgroundColor: Color = .mbBackground
    
    // reticle tooltip text
    public var reticleTooltipFont: Font = .callout
    
    // help button
    public var helpButtonForegroundColor: Color = .mbSecondary
    public var helpButtonBackgroundColor: Color = .mbHelpBackground
    
    // help button tooltip
    public var helpButtonTooltipForegroundColor: Color = .white
    public var helpButtonTooltipBackgroundColor: Color = .mbNeedHelpTooltipBackground
    
    // Toast
    public var toastBackgroundColor: Color = .mbToastBackground
}
