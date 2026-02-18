//
//  SwiftCxxBridge.hpp
//  BlinkCard
//
//  Created by Jura Skrlec on 20.01.2025..
//

#pragma once

// missing in Inputs.hpp within runner, so until fixed package gets propagated, this include is needed here
//#include <tuple>

#import "Frame/InputImage.hpp"
#import "BlinkCard/NativeBlinkCardScanningSession.hpp"
#import "NativeBlinkCard.hpp"
#import "License/NativeLicenseProvider.hpp"
#import "Ping/NativePingManagerHelper.hpp"
//#import "Shared/NativeSettings.hpp"
#import "BlinkCard/NativeUtils.hpp"
#import "BlinkCard/NativeCardAccountResult.hpp"
#import "BlinkCard/NativeDate.hpp"
#import "BlinkCard/NativeCroppedImageResult.hpp"
