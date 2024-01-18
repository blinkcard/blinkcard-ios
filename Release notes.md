# Release notes

## 2.9.0

### What's new in the BlinkCard Recognizer?
- Improved scanning performance and added support for virtually any card layout
- Improved IBAN parser which now supports more IBAN formats
- Added option `allowInvalidCardNumber` which allows reading invalid card numbers to avoid endless scanning on samples and test cards:
    - use with care as it might reduce accuracy in certain situations in production
    - for invalid card number the flag `cardNumberValid` in `BlinkCardRecognizerResult` will be set to `false`


### Improvements
- Better support for RTL languages in our default UX

### Breaking API changes:
- Removed legacy recognizers: `LegacyBlinkCardRecognizer` and `LegacyBlinkCardEliteRecognizer`

## 2.8.2

### New features:
- Added reticle customizations in `MBCBlinkCardOverlayTheme`:
    - UIImage `defaultReticleImage` - 
    - UIImage `errorReticleImage`
    - UIImage `reticleColor`
    - UIColor `reticleDefaultColor`

## 2.8.1

- Internal improvements

## 2.8.0

### Improvements
- Included hand, photocopy, and screen detection models to achieve liveness functionality
- Added anonymization info on which side was anonymized. String data is anonymized using an asterisk instead of blanking the result. 
- Expanded the number of supported credit card types by 100%.
- Improved data extraction, including a 30% reduction in incorrect processing of CVV field.

### What's new in the BlinkCard Recognizer?
- Added new properties `handScaleThreshold`, `handDocumentOverlapThreshold`, `screenAnalysisMatchLevel`, `photocopyAnalysisMatchLevel`. These settings define behaviour of the new liveness features.
- Added a new delegate `BlinkCardRecognizerDelegate` with a callback `livenessStatusCallback` that is called when each side of a card is scanned. It is called with one parameter, a `LivenessStatus` enum.

### BlinkCard Recognizer Result
- Two new booleans: `firstSideAnonymized` and `secondSideAnonymized`.
- New property `DocumentLivenessCheckResult` which has new liveness model results.

## 2.7.0
### New features:
- Improved support for diverse credit card designs. 

#### New user instructions that lead to successful scans
- More detailed instructions on how to scan credit cards, via an intro tutorial or tooltip during scanning, leading to improved success rates in credit card scanning and data extraction.

#### New layout for `BlinkCardOverlayViewController`
- The scanning screen now shows a reticle in the center with scanning instruction.

### What's new in the BlinkCard Recognizer?
- Added a new property `fallbackAnonymization` in `AnonymizationSettings`. If true, anonymization is applied on all fields of the image if extraction is uncertain.
- Improved anonymization performance.

## 2.6.0
​
### Improvements
- We’ve added support for 1000+ new credit card types.
- Decrease of wrongly PAN field processing by 30% for horizontal credit cards, and by 60% for vertical credit cards.
- Improvements in the Anonymization functionality for Quick Read formats on VISA credit cards, as well as general improvements for all other credit card types.

## 2.5.1

### Visual identity update
- We’ve updated Microblink logo and colors

## 2.5.0
### Improvements and fixes:
- Improved date extraction from partial dates.
- Fixed broken anonymization in result screen when the PAN number was anonymized but the image was not. We now correctly anonymize the image too.

## 2.4.0
### Improvements and fixes:
- We now support landscape orientation on [BlinkCardEditViewController](https://blinkcard.github.io/blinkcard-ios/Classes/MBCBlinkCardEditViewController.html) screen
- From now on, BlinkCard reads and extracts the expiry date in MM/YYYY format

## 2.3.0

### New features:

- We’ve added support for vertical payment cards.
- As of this release, BlinkCard supports the Visa Quick Read format (the one where the card number spans through four lines).
- We've changed the threshold for "Camera too far" and "Camera too near" callbacks. From now on, the card needs to be closer to the camera.

### Carthage:

- To use BlinkCard SDK with Carthage, please update to [Carthage v0.38.0](https://github.com/Carthage/Carthage/releases/tag/0.38.0).
- We've added XCFramework support
	- Run `carthage update --use-xcframeworks`

## 2.2.0

### New features:

- We've added support for even more horizonal card layouts
- We've added anonymization options for string and image results:
	- Anonymization is available for these fields:
		- Card number
		- Card number prefix
		- CVV
		- Owner
		- IBAN
	- Choose the `MBCBlinkCardAnonymizationMode` for each field:
		- `None`
		- `ImageOnly` - Black boxes will cover chosen data
		- `ResultFieldsOnly` - String data is redacted from the result, images are not anonymized
		- `FullResult` - Both images and string data are anonymized
	- Card number has further anonymization options available through `MBCCardNumberAnonymizationSettings`:
		- `prefixDigitsVisible` - Defines how many digits at the beginning of the card number remain visible after anonymization
		- `suffixDigitsVisible` - Defines how many digits at the end of the card number remain visible after anonymization

### Bug fixes:

- We've fixed missing `CFBundleVersion` and `CFBundleShortVersionString` from `Info.plist` bug

## 2.1.0

### New features:

- We have full support for Apple Silicon!

### Framework formats and architectures:

- Use `.xcframework` as we now have full Apple Silicon and Intel support.
- We are still supporting `fat binary .framework` format, but we’ve removed simulator slices from it.

### Carthage:

- Carthage still doesn't support `binary .xcframework`, so there is no support for simulator slices anymore.

### Other improvements:

- We’ve updated our default UI with new error messages that appear when a user doesn’t place the card within a frame.
- We’re no longer hiding the security code on the edit results screen.

### Bug fixes:

- We’re now displaying whatever data we manage to extract before a user chooses to enter card details by hand. 

## 2.0.0

### **BlinkCard v2 Release Announcement**

- We're proud to announce our AI-driven BlinkCard v2.0! Extract the **card number** (PAN), **expiry date**, **owner** information (name or company title), **IBAN**, and **CVV**, from a large range of different card layouts.

As of this version, BlinkCard SDK is fully compatible with other Microblink SDKs, which means that you can use it with other Microblink SDKs in the same application.

- BlinkCard v2.0 now scans and extracts data from payment cards with all the information on the back side!

- MBCBlinkCardRecognizer is a Combined recognizer, which means it's designed for scanning **both sides of a card**. However, if all required data is found on the first side, BlinkCard doesn’t require scanning of the back side. In that case, you'll receive results after scanning the side that contains all the information. A set of required fields is defined through the recognizer's settings.

- "Front side" and "back side" are terms more suited to ID scanning. We start the scanning process with the **side containing the card number**. This makes the UX easier for users with cards where all data is on the back side.

- We've expanded the set of possible recognizer states with **StageValid**. This state is set when first side scanning completes with valid data, and second side scanning is required.

- Available [`MBCBlinkCardRecognizer`](https://blinkcard.github.io/blinkcard-ios/Classes/MBCBlinkCardRecognizer.html):
	- You can toggle mandatory **extraction** of all fields except the PAN.
	- You can enable the **blur filter**. When blur filtering is enabled, blurred frames are discarded. Otherwise, we process the blurred frames but set the blur indicator result member.
	- You can define required **padding** around the detected document. This ensures some empty space exists between the document and the edge of the frame.

- [MBCBlinkCardRecognizerResult](https://blinkcard.github.io/blinkcard-ios/Classes/MBCBlinkCardRecognizerResult.html) structure:
    - Contains:
        - The card issuer
        - PAN
        - PAN prefix
        - Expiry date
        - Owner information
        - IBAN
        - CVV
        - Cropped document images
        - Blur indicators for both sides
        - Processing status
	- **Processing status** can be one of:
		- Success - if the process ended successfully and data is valid
		- DetectionFailed - if detection of the document failed
		- ImagePreprocessingFailed - if preprocessing of the image failed
		- StabilityTestFailed - if inconsistent results were detected between different video frames (when video processing, we require at least two frames with consistent data, for image processing this isn't applicable)
		- ScanningWrongSide - if the first side presented in the scanning process does not contain the PAN, or when the user failed to present the second side
		- FieldIdentificationFailed - if we detected a field, but we're unable to parse it (possible glare issues, or a finger covering the field)
		- ImageReturnFailed - failed to return requested images
		- UnsupportedCard - this card layout is currently unsupported.

### New features:

- We added a new `BlinkCard` screen that allows users to edit `MBCBlinkCardRecognizer` scan results:
    - This screen allows users to edit scanned data and input data that wasn't scanned.
    - Enable it by setting `enableEditScreen` to `YES/true` on `MBCBlinkCardOverlaySettings`.
    - Configure which fields should be displayed on this screen by using `fieldConfiguration` property on `MBCBlinkCardOverlaySettings`.
    - Set your custom theme with `MBCBlinkCardOverlayTheme` class
    - Change default strings - follow our Localization guide.
    - To get user-edited fields, implement `blinkCardOverlayViewControllerDidFinishEditing` method from `MBCBlinkCardOverlayViewControllerDelegate` protocol
    - This feature is available only for `MBCBlinkCardRecognizer`.
    - If you are using custom UI, you can launch edit screen by initializing `MBCBlinkCardEditNavigationController` and setting initialized `MBCBlinkCardEditViewController` as root view controller

- We updated the default `MBCBlinkCardOverlayController` scanning screen:
    - Instructions on how to reduce glare wil be displayed when user enables flashlight, you can disable it with `showFlashlightWarning` property on `MBCBlinkCardOverlaySettings`.
    - If edit screen is enabled, new button will show up after 5 seconds of unsuccessful scanning to allow user to go directly to edit screen.

- We added disableMicroblinkLogging method to MBLogger for easier implementation
	- This also enables disabling Microblink logging in Swift.

- We added `Carthage` support
	- For now, `Carthage` is supported for fat binaries, `.framework`. We will support `.xcframework` as soon `Carthage` is updated.
	- Please check out our guide for implementation
- We added `Swift Package Manager` support
	- Please check out our guide for implementation.

### Note on ARM Macs

- We are supporting `ARM64 Device` slice through our `.xcframework` format.
- We are still in development supporting `ARM64 Simulator` slice for newly released ARM Macs and we will update our SDK with `ARM64 Simulator` support as soon as development is done.

### iOS Version support change:

- From now on, we are not supporting **iOS 8** version.

### Cocapods support change:

- We are updating our Cocoapods with `.xcframework` format from now on. Please download [Cocoapods 1.10.0](https://github.com/CocoaPods/CocoaPods/releases/tag/1.10.0) or newer to use our SDK.

### Improvements:

- We have translated complete SDK to following languages: **Arabic(UAE)**, **Chinese simplified**, **Chinese traditional**, **Croatian**, **Czech**, **Dutch**, **English**, **Filipino**, **French**, **German**, **Hewrew**, **Hungarian**, **Indonesian**, **Italian**, **Malay**, **Portuguese**, **Romanian**, **Slovak**, **Spanish**, **Slovenian**, **Thai** and **Vietnamese**.
- We have improved recognition timeout logic when using `MBCBlinkCardRecognizer`.
    - When credit card has multiple sides to scan, timeout timer for the second side starts after the second side of the card has been detected. Previously, it has been started immediately after the first side has been scanned.
    - Timeout duration can be configured by using `partialRecognitionTimeout` on `MBCRecognizerCollection`

### Major API changes:

- To ensure compatibilty with other Microblink SDKs, we have reprefixed all classes. All classes have `MBC` prefix instead of `MB`
- We have renamed framework from `Microblink` to `BlinkCard`
- We added error callback when setting license keys on `MBCMicroblinkSDK`
	- You will be getting error callback and reason why you could not unlock SDK - see `MBCLicenseError`
- We moved all resources inside framework, we are not shipping bundle anymore.

### Minor API changes:

- We have renamed old `MBBlinkCardRecognizer` and `MBBlinkCardEliteRecognizer` recognizers to `MBCLegacyBlinkCardRecognizer` and `MBCLegacyBlinkCardEliteRecognizer`. They are now deprecated.
- We renamed `MBRecogitionMode` to `MBCRecognitionDebugMode` in `MBCRecognizerCollection`.
- Swift:
	- We renamed all `sharedInstance` to `shared`
	- All enums are now `Int`
	- All `unsigned integers` are now `Int`

### Bug fixes:

- We fixed race conditions and camera asserts that could sometimes cause crashes.
- We removed OpenGL entirely which was causing unexpected crashes.
- We added a nullable attribute to the `recognizerRunnerViewControllerWithOverlayViewController` to fix a force unwrapping issue in Swift that could occur if the camera is broken or not working.

## 1.2.0

### New features:

- Introducing support for new framework format - XCFramework:
	- it contains all the necessary device and simulator architecture slices
	- no neeed to remove simulator slices before distributing your app to the App Store as described [here](https://github.com/blinkcard/blinkcard-ios#unsupported-architectures-when-submitting-app-to-app-store)
	- for now, only available from this repo, **not available on Cocoapods**
- Added presets for camera - Preset1080p, and 4K; Optimal always chooses the highest quality
- We added the option to disable Microblink logs in the console output. Use `MBLogger` class and conform to `MBLoggerDelegate` in `AppDelegate`. To disable logs, implement delegate method `- (void)log:(MBLogLevel)level format:(const char *)format arguments:(va_list)arguments`. Be careful with this option. We need full log outputs from the application for support purposes. In case of having problems with scanning certain items, undesired behavior on the specific device(s), crashes inside SDK or anything unmentioned, we will need a full log from your side. If you disable Microblink logging, you won't be able to provide us this information. Hence support might be limited
- We are now delivering the complete list of open source dependencies used in the SDK. Please check the `open-source-software-used` directory

### Improvements in existing features:

- When using `MBPermissionDeniedViewController`, it will prefer `CFBundleDisplayName` over `CFBundleName`

### Bug fixes:

- Fixed missing umbrella headers - you can now use `MBCustomOverlayViewController` to create custom scanning views
- Large memory consumption introduced in v1.1.1 is due to 4K video session on all 4K eligible iPhones; we introduced new camera presets 1080p and 4K, so to reduce your app memory consumption set camera preset on 1080p or 720p
- Fixed catching exceptions as setting license key from `MBMicroblinkSDK`

## 1.1.1

- Bugfixes:
	- added missing `extractIban` property which says it should extract the payment card's IBAN
	- fixed Torch activation for all iOS versions
	- fixed OpenGL code which was fragile and sensitive to crashes if used from multiple threads

## 1.1.0

- Major API changes:
    - Swift Module has been renamed from `MicroBlink` to `Microblink`

- Minor API changes:
    - methods `pauseScanning` and `resumeScanningAndResetState` in `MBRecognizerRunnerViewController` do not return anymore `BOOL`
        - use `isScanningPaused` to check if scanning is paused

- Improvements in ID scanning performance:
	- improved `MBBlinkCardRecognizer`:
	       - now extracts IBAN from the Payment / Debit card
	- in `MBBlinkCardRecognizerResult` and `MBBlinkCardEliteRecognizerResult`, `documentDataMatch` value is now returned as `MBDataMatchResult` enum with three possible values: `NotPerformed`,  `Failed` and `Success`

- Bugfixes:
    - fixed bug in `MBBlinkCardRecognizer`:
        - `anonymizeCvv` now works independently of any other anonymization setting
    - fixed memory leaks that could cause crashes in some cases
    - fixed turning on/off flashlight on iOS 13.1.3

## 1.0.1

- fixed bug in `MBBlinkCardOverlayViewController` which caused memory issues

## 1.0.0

- BlinkCard framework that includes only the capability to scan payment cards.
