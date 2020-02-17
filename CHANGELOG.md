# Release notes

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
