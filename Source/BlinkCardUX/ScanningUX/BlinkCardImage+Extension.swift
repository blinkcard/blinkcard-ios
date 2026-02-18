//  Created by Toni Kreso on 11.02.2026..
//  Copyright (c) Microblink. All rights reserved.
//  This code is provided for use as-is and may not be copied, modified, or redistributed.
//

import SwiftUI

// custom images
extension Image {
    static var frontCardImage: Image {
        Image("front_card", bundle: Bundle.frameworkBundle)
    }
    
    static var backCardImage: Image {
        Image("back_card", bundle: Bundle.frameworkBundle)
    }
    
    static var allCardFieldsVisibleImage: Image {
        Image("all_fields_visible", bundle: Bundle.frameworkBundle)
    }
    
    static var harshLightCardImage: Image {
        Image("harsh_light", bundle: Bundle.frameworkBundle)
    }
    
    static var keepCardStillImage: Image {
        Image("keep_still", bundle: Bundle.frameworkBundle)
    }
    
    static var scanNumberFirstImage: Image {
        Image("scan_number_first", bundle: Bundle.frameworkBundle)
    }
    
    static var cardNumberImage: Image {
        Image("card_number", bundle: Bundle.frameworkBundle)
    }
}
