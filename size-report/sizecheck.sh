#!/bin/sh

xcodebuild -project ../Samples/BlinkCard-sample-Swift/BlinkCard-sample-Swift.xcodeproj/ -sdk iphoneos archive -archivePath app.xcarchive -scheme BlinkCard-sample-Swift

xcodebuild -exportArchive -archivePath app.xcarchive -exportPath app.ipa -exportOptionsPlist exportOptions.plist -allowProvisioningUpdates

cp "app.ipa/App Thinning Size Report.txt" .
