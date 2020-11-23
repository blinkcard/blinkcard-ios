## 2.0.0

### iOS Version support change:

- From now on, we are not supporting **iOS 8** version.

### Cocapods support change:

- We are updating our Cocoapods with `.xcframework` format from now on. Please download [Cocoapods 1.10.0](https://github.com/CocoaPods/CocoaPods/releases/tag/1.10.0) or newer to use our SDK.

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

### Known issues:

- SDK crashes on armv7 devices if bitcode is enabled. We are working on it.

## 1.2.0

- No changes

## 1.1.1

- No changes

## 1.1.0

- Major API changes:
    - Swift Module has been renamed from `MicroBlink` to `Microblink`

- Minor API changes:
    - methods `pauseScanning` and `resumeScanningAndResetState` in `MBRecognizerRunnerViewController` do not return anymore `BOOL`
        - use `isScanningPaused` to check if scanning is paused

## 1.0.1

- No changes
