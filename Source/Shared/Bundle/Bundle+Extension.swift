//  Created by Jura Skrlec on 12.02.2025..
//  Copyright (c) Microblink. All rights reserved.
//  This code is provided for use as-is and may not be copied, modified, or redistributed.
//

import Foundation

extension Bundle {
    static var frameworkBundle: Bundle {
#if SWIFT_PACKAGE
        return .module
#else
        return Bundle(for: Camera.self)
#endif
    }
    
    func localizedString(forKey key: String) -> String {
        self.localizedString(forKey: key, value: nil, table: nil)
    }
}

extension String {
    var localizedString: String {
        Bundle.frameworkBundle.localizedString(forKey: self)
    }
}
