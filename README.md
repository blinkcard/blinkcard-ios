<p align="center" >
  <img src="https://raw.githubusercontent.com/wiki/blinkid/blinkid-ios/Images/logo-microblink.png" alt="MicroBlink" title="MicroBlink">
</p>

[![CocoaPods](https://img.shields.io/cocoapods/p/MBBlinkCard.svg)]()
[![Build Status](https://travis-ci.org/blinkcard/blinkcard-ios.svg?branch=master)](https://travis-ci.org/blinkcard/blinkcard-ios)
[![Pod Version](http://img.shields.io/cocoapods/v/MBBlinkCard.svg?style=flat)](http://cocoadocs.org/docsets/MBBlinkCard/)
[![Carthage compatible](https://img.shields.io/badge/Carthage-compatible-4BC51D.svg?style=flat)](https://github.com/Carthage/Carthage)
[![SwiftPM compatible](https://img.shields.io/badge/SwiftPM-compatible-brightgreen.svg)](https://swift.org/package-manager/)

# BlinkCard SDK for payment card scanning

BlinkCard SDK is a delightful component for quick and easy scanning of payment cards. The SDK is powered with [Microblink's](http://www.microblink.com) industry-proven and world leading OCR, and offers:

- integrated camera management
- layered API, allowing everything from simple integration to complex UX customizations.
- lightweight and no internet connection required
- enteprise-level security standards

BlinkCard is a part of family of SDKs developed by [Microblink](http://www.microblink.com) for optical text recognition, barcode scanning, ID document, payment card scanning and many others.

You can start by watching our [step-by-step tutorial](https://vimeo.com/542575362/5f177c26a0), in which you’ll find out how to make BlinkCard SDK a part of your iOS app.
# Table of contents

- [Requirements](#requirements)
- [Quick Start](#quick-start)
- [Advanced BlinkCard integration instructions](#advanced-integration)
	- [Built-in overlay view controllers and overlay subviews](#ui-customizations)
		- [Using `MBCBlinkCardOverlayViewController`](#using-blinkcard-overlay-viewcontroller)
		- [Custom overlay view controller](#using-custom-overlay-viewcontroller)
	- [Direct processing API](#direct-api-processing)
		- [Using Direct API for `NSString` recognition (parsing)](#direct-api-string-processing)
- [`MBCRecognizer` and available recognizers](#recognizer)
- [List of available recognizers](#available-recognizers)
	- [Frame Grabber Recognizer](#frame-grabber-recognizer)
	- [Success Frame Grabber Recognizer](#success-frame-grabber-recognizer)
	- [BlinkCard recognizers](#blinkcard-recognizers)
		- [MBCBlinkCardRecognizer](#blink-card-recognizer)
		- [MBCLegacyBlinkCardRecognizer (deprecated)](#payment-card-recognizers)
		- [MBCLegacyBlinkCardEliteRecognizer (deprecated)](#elite-payment-card-recognizers)
- [Localization](#localization)
- [Troubleshooting](#troubleshooting)
	- [Integration problems](#troubleshooting-integration-problems)
	- [SDK problems](#troubleshooting-sdk-problems)
		- [Licencing problems](#troubleshooting-licensing-problems)
		- [Other problems](#troubleshooting-other-problems)
	- [Frequently asked questions and known problems](#troubleshooting-faq)
- [Size Report](#size-report)
- [Additional info](#info)


# <a name="requirements"></a> Requirements

SDK package contains BlinkCard framework and one or more sample apps which demonstrate framework integration. The framework can be deployed in **iOS 9.0 or later**.

SDK performs significantly better when the images obtained from the camera are focused. Because of that, the SDK can have lower performance on iPad 2 and iPod Touch 4th gen devices, which [don't have camera with autofocus](http://www.adweek.com/socialtimes/ipad-2-rear-camera-has-tap-for-auto-exposure-not-auto-focus/12536). 
# <a name="quick-start"></a> Quick Start

## Getting started with BlinkCard SDK

This Quick Start guide will get you up and performing OCR scanning as quickly as possible. All steps described in this guide are required for the integration.

This guide closely follows the BlinkCard-Sample app in the Samples folder of this repository. We highly recommend you try to run the sample app. The sample app should compile and run on your device, and in the iOS Simulator.

The source code of the sample app can be used as the reference during the integration.

### 1. Initial integration steps

#### Using CocoaPods

- Download and install/update [Cocopods version 1.10.0](https://github.com/CocoaPods/CocoaPods/releases/tag/1.10.0) or newer
- Since the libraries are stored on [Git Large File Storage](https://git-lfs.github.com), you need to install git-lfs by running these commands:
```shell
brew install git-lfs
git lfs install
```

- **Be sure to restart your console after installing Git LFS**
- **Note:** if you already did try adding SDK using cocoapods and it's not working, first install the git-lfs and then clear you cocoapods cache. This should be sufficient to force cocoapods to clone BlinkCard SDK, if it still doesn't work, try deinitializing your pods and installing them again.
- Project dependencies to be managed by CocoaPods are specified in a file called `Podfile`. Create this file in the same directory as your Xcode project (`.xcodeproj`) file.

- If you don't have podfile initialized run the following in your project directory.
```
pod init
```

- Copy and paste the following lines into the TextEdit window:

```ruby
platform :ios, '9.0'
target 'Your-App-Name' do
    pod 'MBBlinkCard', '~> 2.3.0'
end
```

- Install the dependencies in your project:

```shell
$ pod install
```

- From now on, be sure to always open the generated Xcode workspace (`.xcworkspace`) instead of the project file when building your project:

```shell
open <YourProjectName>.xcworkspace
```



#### Using Carthage

BlinkCard SDK is available via [Carthage](https://github.com/Carthage/Carthage). Please check out [Carthage documentation](https://github.com/Carthage/Carthage/blob/master/README.md) if you are new to Carthage.

- Install Carthage. Check out [Installing Carthage guide](https://github.com/Carthage/Carthage#installing-carthage). Please make sure you have [Carthage => v0.38.0](https://github.com/Carthage/Carthage/releases/tag/0.38.0) installed.
- Create a Cartfile in the same directory where your .xcodeproj or .xcworkspace is.
- Add BlinkCard as a dependency to this Cartfile:

```shell
binary "https://github.com/BlinkCard/blinkcard-ios/blob/master/blinkcard-ios.json"
```
- Run ```carthage update --use-xcframeworks```.
- If successful, a Cartfile.resolved file and a Carthage directory will appear in the same directory as your Xcode project.
- Drag the binaries from ```Carthage/Build/<platform>``` into your application’s Xcode project.



#### Using Swift Package Manager

BlinkCard SDK is available as [Swift Package](https://swift.org/package-manager/). Please check out [Swift Package Manager documentation](https://github.com/apple/swift-package-manager) if you are new to Swift Package Manager.

We provide a URL to the public package repository that you can add in Xcode:

```shell
https://github.com/blinkcard/blinkcard-swift-package
```

1. Select your project’s Swift Packages tab:
![Swift Package Project](https://user-images.githubusercontent.com/26868155/99409747-fe15c100-28f1-11eb-879e-57fed8bff5e6.png)

2. Add the BlinkCard Swift package repository URL:
![Swift Package Repo](https://user-images.githubusercontent.com/26868155/99410171-754b5500-28f2-11eb-84a3-fb1ab2c7df59.png)

3. Choose Swift package version

**NOTE: There is a [known issue](https://bugs.swift.org/browse/SR-13343) in Xcode 12 that could cause crash running on real iOS device. Please follow instructions below for the workaround:**

1. Add a new copy files phase in your application’s Build Phase
2. Change the copy files phase’s destination to Frameworks
3. Add a new run script phase script to your app’s target
4. Add the following script to force deep sign the frameworks with your own signing identity:

```shell
find "${CODESIGNING_FOLDER_PATH}" -name '*.framework' -print0 | while read -d $'\0' framework 
do 
    codesign --force --deep --sign "${EXPANDED_CODE_SIGN_IDENTITY}" --preserve-metadata=identifier,entitlements --timestamp=none "${framework}" 
done
```



#### Manual integration

[Download](https://github.com/BlinkCard/blinkcard-ios/releases) latest release (Download .zip or .tar.gz file starting with BlinkCard. DO NOT download Source Code as GitHub does not fully support Git LFS)

OR

Clone this git repository:

- Since the libraries are stored on [Git Large File Storage](https://git-lfs.github.com), you need to install git-lfs by running these commands:
```shell
brew install git-lfs
git lfs install
```

- **Be sure to restart your console after installing Git LFS**

- To clone, run the following shell command:

```shell
git clone git@github.com:BlinkCard/blinkcard-ios.git
```

- Copy BlinkCard.xcframework to your project folder.

- In your Xcode project, open the Project navigator. Drag the BlinkCard.xcframework file to your project, ideally in the Frameworks group, together with other frameworks you're using. When asked, choose "Create groups", instead of the "Create folder references" option.

![Adding BlinkCard.embedded framework to your project](https://user-images.githubusercontent.com/1635933/89505694-535a1680-d7ca-11ea-8c65-678f158acae9.png)

- Since BlinkCard.xcframework is a dynamic framework, you also need to add it to embedded binaries section in General settings of your target and choose option `Embed & Sign`.

![Adding BlinkCard.xcframework to embedded binaries](https://user-images.githubusercontent.com/1635933/89793425-238e7400-db26-11ea-9556-6eedeb6dcc95.png)

- Include the additional frameworks and libraries into your project in the "Linked frameworks and libraries" section of your target settings.

    - libc++.tbd
    - libiconv.tbd
    - libz.tbd

![Adding Apple frameworks to your project](https://user-images.githubusercontent.com/26868155/65599813-f7feab80-df9e-11e9-9612-e285641b272c.png)

### 2. Referencing header file

In files in which you want to use scanning functionality place import directive.

Swift

```swift
import BlinkCard
```

Objective-C

```objective-c
#import <BlinkCard/BlinkCard.h>
```

### 3. Initiating the scanning process

To initiate the scanning process, first decide where in your app you want to add scanning functionality. Usually, users of the scanning library have a button which, when tapped, starts the scanning process. Initialization code is then placed in touch handler for that button. Here we're listing the initialization code as it looks in a touch handler method.

Swift

```swift
class ViewController: UIViewController, MBCBlinkCardOverlayViewControllerDelegate  {

    var blinkCardRecognizer : MBCBlinkCardRecognizer?

    override func viewDidLoad() {
        super.viewDidLoad()
    }

    @IBAction func didTapScan(_ sender: AnyObject) {

        /** Create BlinkCard recognizer */
        blinkCardRecognizer = MBCBlinkCardRecognizer()

        /** Create BlinkCard settings */
        let settings : MBCBlinkCardOverlaySettings = MBCBlinkCardOverlaySettings()

        /** Crate recognizer collection */
        let recognizerList = [blinkCardRecognizer!]
        let recognizerCollection : MBCRecognizerCollection = MBCRecognizerCollection(recognizers: recognizerList)

        /** Create your overlay view controller */
        let blinkCardOverlayViewController = MBCBlinkCardOverlayViewController(settings: settings, recognizerCollection: recognizerCollection, delegate: self)

        /** Create recognizer view controller with wanted overlay view controller */
        let recognizerRunneViewController : UIViewController = MBCViewControllerFactory.recognizerRunnerViewController(withOverlayViewController: blinkCardOverlayViewController)

        /** Present the recognizer runner view controller. You can use other presentation methods as well (instead of presentViewController) */
        self.present(recognizerRunneViewController, animated: true, completion: nil)
    }
}
```

Objective-C

```objective-c
@interface ViewController () <MBCBlinkCardOverlayViewControllerDelegate>

@property (nonatomic, strong) MBCBlinkCardRecognizer *blinkCardRecognizer;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [MBCMicroblinkSDK.sharedInstance setLicenseResource:@"blinkid-license" withExtension:@"txt" inSubdirectory:@"" for:Bundle.main];
}


- (IBAction)didTapScan:(id)sender {

    /** Create BlinkCard recognizer */
    self.blinkCardRecognizer = [[MBCBlinkCardRecognizer alloc] init];

     /** Create BlinkCard settings */
    MBCBlinkCardOverlaySettings* settings = [[MBCBlinkCardOverlaySettings alloc] init];

    /** Create recognizer collection */
    MBCRecognizerCollection *recognizerCollection = [[MBCRecognizerCollection alloc] initWithRecognizers:@[self.blinkCardRecognizer]];

    /** Create your overlay view controller */
    MBCBlinkCardOverlayViewController *blinkCardOverlayViewController = [[MBCBlinkCardOverlayViewController alloc] initWithSettings:settings recognizerCollection:recognizerCollection delegate:self];

    /** Create recognizer view controller with wanted overlay view controller */
    UIViewController<MBCRecognizerRunnerViewController>* recognizerRunnerViewController = [MBCViewControllerFactory recognizerRunnerViewControllerWithOverlayViewController: blinkCardOverlayViewController];

    /** Present the recognizer runner view controller. You can use other presentation methods as well (instead of presentViewController) */
    [self presentViewController:recognizerRunnerViewController animated:YES completion:nil];

}

@end
```

### 4. License key

A valid license key is required to initalize scanning. You can generate a free trial license key, after you register, at [Microblink developer dashboard](https://microblink.com/login).

You can include the license key in your app by passing a string or a file with license key.
**Note** that you need to set the license key before intializing scanning. Ideally in `AppDelegate` or `viewDidLoad` before initializing any recognizers.

#### License key as string
You can pass the license key as a string, the following way:

Swift

```swift
MBCMicroblinkSDK.shared().setLicenseKey("LICENSE-KEY")
```

Objective-C

```objective-c
[[MBCMicroblinkSDK sharedInstance] setLicenseKey:@"LICENSE-KEY"];
```

#### License key as file
Or you can include the license key, with the code below. Please make sure that the file that contains the license key is included in your project and is copied during **Copy Bundle Resources** build phase.

Swift

```swift
MBCMicroblinkSDK.shared().setLicenseResource("license-key-file", withExtension: "txt", inSubdirectory: "directory-to-license-key", for: Bundle.main)
```

Objective-C

```objective-c
[[MBCMicroblinkSDK sharedInstance] setLicenseResource:@"license-key-file" withExtension:@"txt" inSubdirectory:@"" forBundle:[NSBundle mainBundle]];
```

If the licence is invalid or expired then the methods above will throw an **exception**.

### 5. Registering for scanning events

In the previous step, you instantiated [`MBCBlinkCardOverlayViewController`](http://blinkcard.github.io/blinkcard-ios//Classes/MBCBlinkCardOverlayViewController.html) object with a delegate object. This object gets notified on certain events in scanning lifecycle. In this example we set it to `self`. The protocol which the delegate has to implement is [`MBCBlinkCardOverlayViewControllerDelegate`](http://blinkcard.github.io/blinkcard-ios//Protocols/MBCBlinkCardOverlayViewControllerDelegate.html) protocol. It is necessary to conform to that protocol. We will discuss more about protocols in [Advanced integration section](#advanced-integration). You can use the following default implementation of the protocol to get you started.

Swift

```swift
func blinkCardOverlayViewControllerDidFinishScanning(_ blinkCardOverlayViewController: MBCBlinkCardOverlayViewController, state: MBCRecognizerResultState) {

    // this is done on background thread
    // check for valid state
    if state == .valid {

        // first, pause scanning until we process all the results
        blinkCardOverlayViewController.recognizerRunnerViewController?.pauseScanning()

        DispatchQueue.main.async(execute: {() -> Void in
            // All UI interaction needs to be done on main thread
        })
    }
}

func blinkCardOverlayViewControllerDidTapClose(_ blinkCardOverlayViewController: MBCBlinkCardOverlayViewController) {
    // Your action on cancel
}
```

Objective-C

```objective-c
- (void)blinkCardOverlayViewControllerDidFinishScanning:(MBCBlinkCardOverlayViewController *)blinkCardOverlayViewController state:(MBCRecognizerResultState)state {

    // this is done on background thread
    // check for valid state
    if (state == MBCRecognizerResultStateValid) {

        // first, pause scanning until we process all the results
        [blinkCardOverlayViewController.recognizerRunnerViewController pauseScanning];

        dispatch_async(dispatch_get_main_queue(), ^{
            // All UI interaction needs to be done on main thread
        });
    }
}

- (void)blinkCardOverlayViewControllerDidTapClose:(nonnull MBCBlinkCardOverlayViewController *)blinkCardOverlayViewController {
    // Your action on cancel
}
```

# <a name="advanced-integration"></a> Advanced BlinkCard integration instructions
This section covers more advanced details of BlinkCard integration.

1. [First part](#ui-customizations) will cover the possible customizations when using UI provided by the SDK.
2. [Second part](#using-document-overlay-viewcontroller) will describe how to embed [`MBCRecognizerRunnerViewController's delegates`](http://blinkcard.github.io/blinkcard-ios/Protocols.html) into your `UIViewController` with the goal of creating a custom UI for scanning, while still using camera management capabilites of the SDK.
3. [Third part](#direct-api-processing) will describe how to use the [`MBCRecognizerRunner`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizerRunner.html) (Direct API) for recognition directly from `UIImage` without the need of camera or to recognize camera frames that are obtained by custom camera management.
4. [Fourth part](#recognizer) will describe recognizer concept and available recognizers.


## <a name="ui-customizations"></a> Built-in overlay view controllers and overlay subviews

Within BlinkCard SDK there are several built-in overlay view controllers and scanning subview overlays that you can use to perform scanning. 
### <a name="using-blinkcard-overlay-viewcontroller"></a> Using `MBCBlinkCardOverlayViewController`

[`MBCBlinkCardOverlayViewController`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCBlinkCardOverlayViewController.html) is overlay view controller best suited for performing scanning of payment cards for both front and back side. It has [`MBCBlinkCardOverlayViewControllerDelegate`](http://blinkcard.github.io/blinkcard-ios/Protocols/MBCBlinkCardOverlayViewControllerDelegate.html) delegate which can be used out-of-the-box to perform scanning using the default UI. Here is an example how to use and initialize [`MBCBlinkCardOverlayViewController`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCBlinkCardOverlayViewController.html):

Swift

```swift
/** Create your overlay view controller */
let blinkCardViewController : MBCBlinkCardOverlayViewController = MBCBlinkCardOverlayViewController(settings: blinkCardSettings, recognizerCollection: recognizerCollection, delegate: self)

/** Create recognizer view controller with wanted overlay view controller */
let recognizerRunneViewController : UIViewController = MBCViewControllerFactory.recognizerRunnerViewController(withOverlayViewController: blinkCardViewController)

/** Present the recognizer runner view controller. You can use other presentation methods as well (instead of presentViewController) */
self.present(recognizerRunneViewController, animated: true, completion: nil)
```

Objective-C

```objective-c
MBCDocumentVerificationOverlayViewController *overlayVC = [[MBCBlinkCardOverlayViewController alloc] initWithSettings:settings recognizerCollection: recognizerCollection delegate:self];
UIViewController<MBCRecognizerRunnerViewController>* recognizerRunnerViewController = [MBCViewControllerFactory recognizerRunnerViewControllerWithOverlayViewController:overlayVC];

/** Present the recognizer runner view controller. You can use other presentation methods as well (instead of presentViewController) */
[self presentViewController:recognizerRunnerViewController animated:YES completion:nil];
```

As you can see, when initializing [`MBCDocumentVerificationOverlayViewController`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCDocumentVerificationOverlayViewController.html), we are sending delegate property as `self`. To get results, we need to conform to [`MBCDocumentVerificationOverlayViewControllerDelegate`](http://blinkcard.github.io/blinkcard-ios/Protocols/MBCDocumentVerificationOverlayViewControllerDelegate.html) protocol.

### Edit results screen

SDK also provides an overlay view controller that allows users to edit scanned results and input data that wasn't scanned. Note that this view controller works only with `MBCBlinkCardRecognizer`.

Enable edit screen by setting property `enableEditScreen = YES/true` on `MBCBlinkCardOverlaySettings`. It is enabled by default.

If edit screen is enabled, you must implement `blinkCardOverlayViewControllerDidFinishEditing` delegate method from `MBCBlinkCardOverlayViewControllerDelegate` protocol to get edited results. It returns `MBCBlinkCardOverlayViewController` and `MBCBlinkCardEditResult` object. You can still get original results and images from `MBCBlinkCardRecognizerResult`.

Edit results view controller can be customised in several ways:

- to configure which fields should be displayed use `fieldConfiguration` property of type [`MBCBlinkCardEditFieldConfiguration`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCBlinkCardEditFieldConfiguration.html)
- set your custom theme with [`MBCBlinkCardEditOverlayTheme`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCBlinkCardEditOverlayTheme.html)
- for setting custom strings, please check out our [Localization guide](#localization)

#### Edit results screen in Custom UI

SDK also provides options to use `MBCBlinkCardEditViewController` with Custom UI. Initalize it and, add it to `{ class_prefix }}BlinkCardEditNavigationController` and present it.

```swift
let blinkCardEditViewController = MBCBlinkCardEditViewController(delegate: self)
let navigationController = MBCBlinkCardEditNavigationController(rootViewController: blinkCardEditViewController)
```

```objective-c
self.blinkCardEditViewController = [[MBCBlinkCardEditViewController alloc] initWithDelegate:self];
self.navigationController = [[MBCBlinkCardEditNavigationController alloc] initWithRootViewController:self.blinkCardEditViewController];
```
### <a name="using-custom-overlay-viewcontroller"></a> Custom overlay view controller

Please check our Samples for custom implementation of overlay view controller.

Overlay View Controller is an abstract class for all overlay views.

It's responsibility is to provide meaningful and useful interface for the user to interact with.

Typical actions which need to be allowed to the user are:

- intuitive and meaniningful way to guide the user through scanning process. This is usually done by presenting a "viewfinder" in which the user need to place the scanned object
- a way to cancel the scanning, typically with a "cancel" or "back" button
- a way to power on and off the light (i.e. "torch") button

BlinkCard SDK always provides it's own default implementation of the Overlay View Controller for every specific use. Your implementation should closely mimic the default implementation as it's the result of thorough testing with end users. Also, it closely matches the underlying scanning technology.

For example, the scanning technology usually gives results very fast after the user places the device's camera in the expected way above the scanned object. This means a progress bar for the scan is not particularly useful to the user. The majority of time the user spends on positioning the device's camera correctly. That's just an example which demonstrates careful decision making behind default camera overlay view.

### 1. Subclassing

To use your custom overlay with Microblink's camera view, you must first subclass [`MBCCustomOverlayViewController`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCCustomOverlayViewController.html) and implement the overlay behaviour conforming wanted protocols.

### 2. Protocols

There are five [`MBCRecognizerRunnerViewController`](http://blinkcard.github.io/blinkcard-ios/Protocols/MBCRecognizerRunnerViewController.html) protocols and one overlay protocol [`MBCOverlayViewControllerInterface`](http://blinkcard.github.io/blinkcard-ios/Protocols/MBCOverlayViewControllerInterface.html).

Five `RecognizerRunnerView` protocols are:
- [`MBCScanningRecognizerRunnerViewControllerDelegate`](http://blinkcard.github.io/blinkcard-ios/Protocols/MBCScanningRecognizerRunnerViewControllerDelegate.html)
- [`MBCDetectionRecognizerRunnerViewControllerDelegate`](http://blinkcard.github.io/blinkcard-ios/Protocols/MBCDetectionRecognizerRunnerViewControllerDelegate.html)
- [`MBCOcrRecognizerRunnerViewControllerDelegate`](http://blinkcard.github.io/blinkcard-ios/Protocols/MBCOcrRecognizerRunnerViewControllerDelegate.html)
- [`MBCDebugRecognizerRunnerViewControllerDelegate`](http://blinkcard.github.io/blinkcard-ios/Protocols/MBCDebugRecognizerRunnerViewControllerDelegate.html)
- [`MBCRecognizerRunnerViewControllerDelegate`](http://blinkcard.github.io/blinkcard-ios/Protocols/MBCRecognizerRunnerViewControllerDelegate.html)

In `viewDidLoad`, other protocol conformation can be done and it's done on `recognizerRunnerViewController` property of [`MBCOverlayViewController`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCOverlayViewController.html), for example:

Swift and Objective-C
```swift
self.scanningRecognizerRunnerViewControllerDelegate = self;
```

### 3. Initialization
In [Quick Start](#quick-start) guide it is shown how to use a default overlay view controller. You can now swap default view controller with your implementation of `CustomOverlayViewController`

Swift
```swift
let recognizerRunnerViewController : UIViewController = MBCViewControllerFactory.recognizerRunnerViewController(withOverlayViewController: CustomOverlayViewController)
```

Objective-C
```objective-c
UIViewController<MBCRecognizerRunnerViewController>* recognizerRunnerViewController = [MBCViewControllerFactory recognizerRunnerViewControllerWithOverlayViewController:CustomOverlayViewController];
```

## <a name="direct-api-processing"></a> Direct processing API

This guide will in short present you how to process UIImage objects with BlinkCard SDK, without starting the camera video capture.

With this feature you can solve various use cases like:
	- recognizing text on images in Camera roll
	- taking full resolution photo and sending it to processing
	- scanning barcodes on images in e-mail etc.

DirectAPI-sample demo app here will present UIImagePickerController for taking full resolution photos, and then process it with BlinkCard SDK to get scanning results using Direct processing API.

Direct processing API is handled with [`MBCRecognizerRunner`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizerRunner.html). That is a class that handles processing of images. It also has protocols as [`MBCRecognizerRunnerViewController`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizerRunnerViewController.html).
Developer can choose which protocol to conform:

- [`MBCScanningRecognizerRunnerDelegate`](http://blinkcard.github.io/blinkcard-ios/Protocols/MBCScanningRecognizerRunnerDelegate.html)
- [`MBCDetectionRecognizerRunnerDelegate`](http://blinkcard.github.io/blinkcard-ios/Protocols/MBCDetectionRecognizerRunnerDelegate.html)
- [`MBCDebugRecognizerRunnerDelegate`](http://blinkcard.github.io/blinkcard-ios/Protocols/MBCDebugRecognizerRunnerDelegate.html)
- [`MBCOcrRecognizerRunnerDelegate`](http://blinkcard.github.io/blinkcard-ios/Protocols/MBCOcrRecognizerRunnerDelegate.html)

In example, we are conforming to [`MBCScanningRecognizerRunnerDelegate`](http://blinkcard.github.io/blinkcard-ios/Protocols/MBCScanningRecognizerRunnerDelegate.html) protocol.

To initiate the scanning process, first decide where in your app you want to add scanning functionality. Usually, users of the scanning library have a button which, when tapped, starts the scanning process. Initialization code is then placed in touch handler for that button. Here we're listing the initialization code as it looks in a touch handler method.

Swift
```swift
func setupRecognizerRunner() {
    var recognizers = [MBCRecognizer]()
    recognizer = MBCBlinkCardRecognizer()
    recognizers.append(recognizer!)
    let recognizerCollection = MBCRecognizerCollection(recognizers: recognizers)
    recognizerRunner = MBCRecognizerRunner(recognizerCollection: recognizerCollection)
    recognizerRunner?.scanningRecognizerRunnerDelegate = self
}

func processImageRunner(_ originalImage: UIImage) {
    var image: MBCImage? = nil
    if let anImage = originalImage {
        image = MBCImage(uiImage: anImage)
    }
    image?.cameraFrame = true
    image?.orientation = MBCProcessingOrientation.left
    let _serialQueue = DispatchQueue(label: "com.microblink.DirectAPI-sample-swift")
    _serialQueue.async(execute: {() -> Void in
        self.recognizerRunner?.processImage(image!)
    })
}

func recognizerRunner(_ recognizerRunner: MBCRecognizerRunner, didFinishScanningWith state: MBCRecognizerResultState) {
    if recognizer.result.resultState == MBCRecognizerResultStateValid {
        // Handle result
    }
}
```

Objective-C
```objective-c
- (void)setupRecognizerRunner {
    NSMutableArray<MBCRecognizer *> *recognizers = [[NSMutableArray alloc] init];

    self. recognizer = [[MBCBlinkCardRecognizer alloc] init];

    [recognizers addObject: self.recognizer];

    MBCRecognizerCollection *recognizerCollection = [[MBCRecognizerCollection alloc] initWithRecognizers:recognizers];

    self.recognizerRunner = [[MBCRecognizerRunner alloc] initWithRecognizerCollection:recognizerCollection];
    self.recognizerRunner.scanningRecognizerRunnerDelegate = self;
}

- (void)processImageRunner:(UIImage *)originalImage {
    MBCImage *image = [MBCImage imageWithUIImage:originalImage];
    image.cameraFrame = YES;
    image.orientation = MBCProcessingOrientationLeft;
    dispatch_queue_t _serialQueue = dispatch_queue_create("com.microblink.DirectAPI-sample", DISPATCH_QUEUE_SERIAL);
    dispatch_async(_serialQueue, ^{
        [self.recognizerRunner processImage:image];
    });
}

- (void)recognizerRunner:(nonnull MBCRecognizerRunner *)recognizerRunner didFinishScanningWithState:(MBCRecognizerResultState)state {
    if (self.recognizer.result.resultState == MBCRecognizerResultStateValid) {
        // Handle result
    }
}
```

Now you've seen how to implement the Direct processing API.

In essence, this API consists of two steps:

- Initialization of the scanner.
- Call of `- (void)processImage:(MBCImage *)image;` method for each UIImage or CMSampleBufferRef you have.


### <a name="direct-api-string-processing"></a> Using Direct API for `NSString` recognition (parsing)

Some recognizers support recognition from `NSString`. They can be used through Direct API to parse given `NSString` and return data just like when they are used on an input image. When recognition is performed on `NSString`, there is no need for the OCR. Input `NSString` is used in the same way as the OCR output is used when image is being recognized.
Recognition from `String` can be performed in the same way as recognition from image.
The only difference is that user should call `- (void)processString:(NSString *)string;` on [`MBCRecognizerRunner`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizerRunner.html).

# <a name="recognizer"></a> `MBCRecognizer` and available recognizers

## The `MBCRecognizer` concept

The [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizer.html) is the basic unit of processing within the SDK. Its main purpose is to process the image and extract meaningful information from it. As you will see [later](#available-recognizers), the SDK has lots of different [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizer.html) objects that have various purposes.

Each [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizer.html) has a [`MBCRecognizerResult`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizerResult.html) object, which contains the data that was extracted from the image. The [`MBCRecognizerResult`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizerResult.html) object is a member of corresponding [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizer.html) object its lifetime is bound to the lifetime of its parent [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizer.html) object. If you need your `MBCRecognizerResult` object to outlive its parent [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizer.html) object, you must make a copy of it by calling its method `copy`.

While [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizer.html) object works, it changes its internal state and its result. The [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizer.html) object's [`MBCRecognizerResult`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizerResult.html) always starts in `Empty` state. When corresponding [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizer.html) object performs the recognition of given image, its [`MBCRecognizerResult`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizerResult.html) can either stay in `Empty` state (in case [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizer.html)failed to perform recognition), move to `Uncertain` state (in case [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizer.html) performed the recognition, but not all mandatory information was extracted) or move to `Valid` state (in case [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizer.html) performed recognition and all mandatory information was successfully extracted from the image).

As soon as one [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizer.html) object's [`MBCRecognizerResult`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizerResult.html) within [`MBCRecognizerCollection`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizerCollection.html) given to `MBCRecognizerRunner` or `MBCRecognizerRunnerViewController` changes to `Valid` state, the `onScanningFinished` callback will be invoked on same thread that performs the background processing and you will have the opportunity to inspect each of your [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizer.html) objects' [`MBCRecognizerResult`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizerResult.html) to see which one has moved to `Valid` state.

As soon as `onScanningFinished` method ends, the `MBCRecognizerRunnerViewController` will continue processing new camera frames with same [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizer.html) objects, unless `paused`. Continuation of processing or `reset` recognition will modify or reset all [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizer.html) objects's [`MBCRecognizerResult`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizerResult.html). When using built-in activities, as soon as `onScanningFinished` is invoked, built-in activity pauses the `MBCRecognizerRunnerViewController` and starts finishing the activity, while saving the [`MBCRecognizerCollection`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizerCollection.html) with active [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizer.html).

## `MBCRecognizerCollection` concept

The [`MBCRecognizerCollection`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizerCollection.html) is is wrapper around [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizer.html) objects that has array of [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizer.html) objects that can be used to give [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizer.html) objects to `MBCRecognizerRunner` or `MBCRecognizerRunnerViewController` for processing.

The [`MBCRecognizerCollection`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizerCollection.html) is always constructed with array `[[MBCRecognizerCollection alloc] initWithRecognizers:recognizers]` of [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizer.html) objects that need to be prepared for recognition (i.e. their properties must be tweaked already).

The [`MBCRecognizerCollection`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizerCollection.html) manages a chain of [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizer.html) objects within the recognition process. When a new image arrives, it is processed by the first [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizer.html) in chain, then by the second and so on, iterating until a [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizer.html) object's [`MBCRecognizerResult`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizerResult.html) changes its state to `Valid` or all of the [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizer.html) objects in chain were invoked (none getting a `Valid` result state).

You cannot change the order of the [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizer.html) objects within the chain - no matter the order in which you give [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizer.html) objects to [`MBCRecognizerCollection`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizerCollection.html), they are internally ordered in a way that provides best possible performance and accuracy. Also, in order for SDK to be able to order [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizer.html) objects in recognition chain in a best way possible, it is not allowed to have multiple instances of [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizer.html) objects of the same type within the chain. Attempting to do so will crash your application.

# <a name="available-recognizers"></a> List of available recognizers

This section will give a list of all [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizer.html) objects that are available within BlinkCard SDK, their purpose and recommendations how they should be used to get best performance and user experience.

## <a name="frame-grabber-recognizer"></a> Frame Grabber Recognizer

The [`MBCFrameGrabberRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCFrameGrabberRecognizer.html) is the simplest recognizer in SDK, as it does not perform any processing on the given image, instead it just returns that image back to its `onFrameAvailable`. Its result never changes state from empty.

This recognizer is best for easy capturing of camera frames with `MBCRecognizerRunnerViewController`. Note that [`MBCImage`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCImage.html) sent to `onFrameAvailable` are temporary and their internal buffers all valid only until the `onFrameAvailable` method is executing - as soon as method ends, all internal buffers of [`MBCImage`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCImage.html) object are disposed. If you need to store [`MBCImage`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCImage.html) object for later use, you must create a copy of it by calling `copy`.

## <a name="success-frame-grabber-recognizer"></a> Success Frame Grabber Recognizer

The [`MBCSuccessFrameGrabberRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCSuccessFrameGrabberRecognizer.html) is a special `MBCecognizer` that wraps some other [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizer.html) and impersonates it while processing the image. However, when the [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizer.html) being impersonated changes its [`MBCRecognizerResult`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizerResult.html) into `Valid` state, the [`MBCSuccessFrameGrabberRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCSuccessFrameGrabberRecognizer.html) captures the image and saves it into its own [`MBCSuccessFrameGrabberRecognizerResult`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCSuccessFrameGrabberRecognizerResult.html) object.

Since [`MBCSuccessFrameGrabberRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCSuccessFrameGrabberRecognizer.html)  impersonates its slave [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizer.html) object, it is not possible to give both concrete [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizer.html) object and `MBCSuccessFrameGrabberRecognizer` that wraps it to same `MBCRecognizerCollection` - doing so will have the same result as if you have given two instances of same [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizer.html) type to the [`MBCRecognizerCollection`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizerCollection.html) - it will crash your application.

This recognizer is best for use cases when you need to capture the exact image that was being processed by some other [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizer.html) object at the time its [`MBCRecognizerResult`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCRecognizerResult.html) became `Valid`. When that happens, `MBCSuccessFrameGrabberRecognizer's` `MBCSuccessFrameGrabberRecognizerResult` will also become `Valid` and will contain described image.

## <a name="blinkcard-recognizers"></a> BlinkCard recognizers
Payment card recognizers are used to scan payment cards.

### <a name="blink-card-recognizer"></a> MBCBlinkCardRecognizer
The MBCBlinkCardRecognizer extracts the card number (PAN), expiry date, owner information (name or company title), IBAN, and CVV, from a large range of different card layouts.

MBCBlinkCardRecognizer is a Combined recognizer, which means it's designed for scanning both sides of a card. However, if all required data is found on the first side, we do not wait for second side scanning. We can return the result early. A set of required fields is defined through the recognizer's settings.

"Front side" and "back side" are terms more suited to ID scanning. We start the scanning process with the side containing the card number. This makes the UX easier for users with cards where all data is on the back side.

### <a name="payment-card-recognizers"></a> MBCLegacyBlinkCardRecognizer (deprecated)
The [`MBCLegacyBlinkCardRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCLegacyBlinkCardRecognizer.html)is used for scanning the [front and back side of Payment / Debit card](https://en.wikipedia.org/wiki/Payment_card).

### <a name="elite-payment-card-recognizers"></a> MBCLegacyBlinkCardEliteRecognizer (deprecated)
The [`MBCLegacyBlinkCardEliteRecognizer`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCLegacyBlinkCardEliteRecognizer.html) scans back side of elite Payment / Debit card after scanning the front side and combines data from both sides.
# <a name="localization"></a> Localization

The SDK is localized on following languages: Arabic, Chinese simplified, Chinese traditional, Croatian, Czech, Dutch, Filipino, French, German, Hebrew, Hungarian, Indonesian, Italian, Malay, Portuguese, Romanian, Slovak, Slovenian, Spanish, Thai, Vietnamese.

If you would like us to support additional languages or report incorrect translation, please contact us at [help.microblink.com](http://help.microblink.com).

If you want to add additional languages yourself or change existing translations, you need to set `customLocalizationFileName` property on [`MBCMicroblinkApp`](http://blinkcard.github.io/blinkcard-ios/Classes/MBCMicroblinkApp.html) object to your strings file name.

For example, let's say that we want to change text "Scan the front side of a document" to "Scan the front side" in BlinkID sample project. This would be the steps:
* Find the translation key in en.strings file inside BlinkCard.framework
* Add a new file MyTranslations.strings to the project by using "Strings File" template
* With MyTranslations.string open, in File inspector tap "Localize..." button and select English
* Add the translation key "blinkid_generic_message" and the value "Scan the front side" to MyTranslations.strings
* Finally in AppDelegate.swift in method `application(_:, didFinishLaunchingWithOptions:)` add `MBCMicroblinkApp.instance()?.customLocalizationFileName = "MyTranslations"`

# <a name="troubleshooting"></a> Troubleshooting

## <a name="troubleshooting-integration-problems"></a> Integration problems

In case of problems with integration of the SDK, first make sure that you have tried integrating it into XCode by following [integration instructions](#quick-start).

If you have followed [XCode integration instructions](#quick-start) and are still having integration problems, please contact us at [help.microblink.com](http://help.microblink.com).

## <a name="troubleshooting-sdk-problems"></a> SDK problems

In case of problems with using the SDK, you should do as follows:

### <a name="troubleshooting-licensing-problems"></a> Licencing problems

If you are getting "invalid licence key" error or having other licence-related problems (e.g. some feature is not enabled that should be or there is a watermark on top of camera), first check the console. All licence-related problems are logged to error log so it is easy to determine what went wrong.

When you have determine what is the licence-relate problem or you simply do not understand the log, you should contact us [help.microblink.com](http://help.microblink.com). When contacting us, please make sure you provide following information:

* exact Bundle ID of your app (from your `info.plist` file)
* licence that is causing problems
* please stress out that you are reporting problem related to iOS version of BlinkCard SDK
* if unsure about the problem, you should also provide excerpt from console containing licence error

### <a name="troubleshooting-other-problems"></a> Other problems

If you are having problems with scanning certain items, undesired behaviour on specific device(s), crashes inside BlinkCard SDK or anything unmentioned, please do as follows:
	
* Contact us at [help.microblink.com](http://help.microblink.com) describing your problem and provide following information:
	* log file obtained in previous step
	* high resolution scan/photo of the item that you are trying to scan
	* information about device that you are using
	* please stress out that you are reporting problem related to iOS version of BlinkCard SDK

## <a name="troubleshooting-faq"></a> Frequently asked questions and known problems
Here is a list of frequently asked questions and solutions for them and also a list of known problems in the SDK and how to work around them.

#### Note on ARM Macs

We are supporting `ARM64 Device` slice through our `.xcframework` format.
We are still in development supporting `ARM64 Simulator` slice for newly released ARM Macs and we will update our SDK with `ARM64 Simulator` support as soon as development is done.

#### In demo everything worked, but after switching to production license I get `NSError` with `MBCMicroblinkSDKRecognizerErrorDomain` and `MBCRecognizerFailedToInitalize` code as soon as I construct specific [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/docs/Classes/MBCRecognizer.html) object

Each license key contains information about which features are allowed to use and which are not. This `NSError` indicates that your production license does not allow using of specific `MBCRecognizer` object. You should contact [support](http://help.microblink.com) to check if provided licence is OK and that it really contains all features that you have purchased.

#### I get `NSError` with `MBCMicroblinkSDKRecognizerErrorDomain` and `MBCRecognizerFailedToInitalize` code with trial license key

Whenever you construct any [`MBCRecognizer`](http://blinkcard.github.io/blinkcard-ios/docs/Classes/MBCRecognizer.html) object or, a check whether license allows using that object will be performed. If license is not set prior constructing that object, you will get `NSError` with `MBCMicroblinkSDKRecognizerErrorDomain` and `MBCRecognizerFailedToInitalize` code. We recommend setting license as early as possible in your app.

#### Undefined Symbols on Architecture armv7

Make sure you link your app with iconv and Accelerate frameworks as shown in [Quick start](#quick-start).
If you are using Cocoapods, please be sure that you've installed `git-lfs` prior to installing pods. If you are still getting this error, go to project folder and execute command `git-lfs pull`.

### Crash on armv7 devices

SDK crashes on armv7 devices if bitcode is enabled. We are working on it.

#### In my `didFinish` callback I have the result inside my `MBCRecognizer`, but when scanning activity finishes, the result is gone

This usually happens when using [`MBCRecognizerRunnerViewController`](http://blinkcard.github.io/blinkcard-ios/docs/Classes/MBCRecognizerRunnerViewController.html) and forgetting to pause the [`MBCRecognizerRunnerViewController`](http://blinkcard.github.io/blinkcard-ios/docs/Classes/MBCRecognizerRunnerViewController.html) in your `didFinish` callback. Then, as soon as `didFinish` happens, the result is mutated or reset by additional processing that `MBCRecognizer` performs in the time between end of your `didFinish` callback and actual finishing of the scanning activity. For more information about statefulness of the `MBCRecognizer` objects, check [this section](#recognizer-concept).

#### Unsupported architectures when submitting app to App Store

BlinkCard.framework is a dynamic framework which contains slices for all architectures - device and simulator. If you intend to extract .ipa file for ad hoc distribution, you'll need to preprocess the framework to remove simulator architectures.

Ideal solution is to add a build phase after embed frameworks build phase, which strips unused slices from embedded frameworks.

Build step is based on the one provided here: http://ikennd.ac/blog/2015/02/stripping-unwanted-architectures-from-dynamic-libraries-in-xcode/

```shell
APP_PATH="${TARGET_BUILD_DIR}/${WRAPPER_NAME}"

# This script loops through the frameworks embedded in the application and
# removes unused architectures.
find "$APP_PATH" -name '*.framework' -type d | while read -r FRAMEWORK
do
FRAMEWORK_EXECUTABLE_NAME=$(defaults read "$FRAMEWORK/Info.plist" CFBundleExecutable)
FRAMEWORK_EXECUTABLE_PATH="$FRAMEWORK/$FRAMEWORK_EXECUTABLE_NAME"
echo "Executable is $FRAMEWORK_EXECUTABLE_PATH"

EXTRACTED_ARCHS=()

for ARCH in $ARCHS
do
echo "Extracting $ARCH from $FRAMEWORK_EXECUTABLE_NAME"
lipo -extract "$ARCH" "$FRAMEWORK_EXECUTABLE_PATH" -o "$FRAMEWORK_EXECUTABLE_PATH-$ARCH"
EXTRACTED_ARCHS+=("$FRAMEWORK_EXECUTABLE_PATH-$ARCH")
done

echo "Merging extracted architectures: ${ARCHS}"
lipo -o "$FRAMEWORK_EXECUTABLE_PATH-merged" -create "${EXTRACTED_ARCHS[@]}"
rm "${EXTRACTED_ARCHS[@]}"

echo "Replacing original executable with thinned version"
rm "$FRAMEWORK_EXECUTABLE_PATH"
mv "$FRAMEWORK_EXECUTABLE_PATH-merged" "$FRAMEWORK_EXECUTABLE_PATH"

done
```

### Disable logging

Logging can be disabled by calling `disableMicroblinkLogging` method on [`MBCLogger`](http://blinkcard.github.io/blinkcard-ios/docs/Classes/MBCLogger.html) instance.
# <a name="size-report"></a> Size Report

We are delivering complete size report of our BlinkCard SDK based on our BlinkCard-sample-Swift sample project. You can check that [here](https://github.com/BlinkCard/blinkcard-ios/tree/master/size-report).
# <a name="info"></a> Additional info

Complete API reference can be found [here](http://blinkcard.github.io/blinkcard-ios/index.html). 

For any other questions, feel free to contact us at [help.microblink.com](http://help.microblink.com).