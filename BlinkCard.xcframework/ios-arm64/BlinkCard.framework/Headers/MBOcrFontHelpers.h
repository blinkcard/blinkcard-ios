//
//  MBOcrFontHelpers.h
//  BlinkOcrFramework
//
//  Created by Jura on 29/07/15.
//  Copyright (c) 2015 Microblink Ltd. All rights reserved.
//

#import "MBOcrFont.h"

#include <ZicerOcrEngine/EngineOptions.hpp>

extern ocr::ZicerFont fontFromPPFont(MBCOcrFont ppfont);

extern MBCOcrFont ppfontFromFont(ocr::ZicerFont font);
