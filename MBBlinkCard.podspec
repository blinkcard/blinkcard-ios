Pod::Spec.new do |s|

  s.name        = "MBBlinkCard"
  s.version     = "2.4.0"
  s.summary     = "A delightful component for payment card scanning"
  s.homepage    = "http://microblink.com"

  s.description = <<-DESC
        BlinkCard SDK is a delightful component for quick and easy scanning of payment cards. The SDK is powered with         [Microblink's](http://www.microblink.com) industry-proven and world leading OCR and barcode scanning technology, and offers:

        - integrated camera management
        - layered API, allowing everything from simple integration to complex UX customizations.
        - lightweight and no internet connection required
        - enteprise-level security standards

        BlinkCard is a part of family of SDKs developed by [Microblink](http://www.microblink.com) for optical text recognition, barcode scanning, ID document scanning, payment card scanning and many others.
        DESC

  s.license     = {
        :type => 'commercial',
        :text => <<-LICENSE
                © 2013-2019 Microblink Ltd. All rights reserved.
                LICENSE
        }

  s.authors     = {
        "Microblink" => "info@microblink.com",
  }

  s.source      = {
        :http => 'https://github.com/BlinkCard/blinkcard-ios/releases/download/v2.4.0/blinkcard-ios_v2.4.0.tar.gz'
  }

  s.platform     = :ios

  # ――― MULTI-PLATFORM VALUES ――――――――――――――――――――――――――――――――――――――――――――――――― #

  s.ios.deployment_target = '9.0.0'
  s.ios.requires_arc = false
  s.ios.vendored_frameworks = 'BlinkCard.xcframework'
  s.ios.frameworks = 'Accelerate', 'AVFoundation', 'AudioToolbox', 'AssetsLibrary', 'CoreMedia', 'ImageIO'
  s.ios.libraries = 'c++', 'iconv', 'z'

end
