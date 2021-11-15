## 2.5.0

- No changes

## 2.4.0

- No changes

## 2.3.0

### Carthage:

- To use BlinkCard SDK with Carthage, please update to [Carthage v0.38.0](https://github.com/Carthage/Carthage/releases/tag/0.38.0).
- We've added XCFramework support
	- Run `carthage update --use-xcframeworks`

## 2.2.0

- No changes

## 2.1.0

### New features:

* We have full support for Apple Silicon!

### Framework formats and architectures:

* Use `.xcframework` as we now have full Apple Silicon and Intel support.
* We are still supporting `fat binary .framework` format, but we’ve removed simulator slices from it.

### Carthage:

* Carthage still doesn't support `binary .xcframework`, so there is no support for simulator slices anymore.

### Minor API changes:

- We've replaced `Using time-limited license!` warning with `Using trial license!` warning. The warning message is displayed when using a trial license key. To disable it, use `showTrialLicenseWarning` on `MBCMicroblinkSDK`.

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
