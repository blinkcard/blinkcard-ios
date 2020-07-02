# Release notes

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
