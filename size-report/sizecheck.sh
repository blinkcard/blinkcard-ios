#!/bin/sh

xcodebuild -project ../Samples/BlinkCard-Sample-Swift/BlinkCard-Sample-Swift.xcodeproj/ -sdk iphoneos archive -archivePath app.xcarchive -scheme BlinkCard-Sample-Swift

xcodebuild -exportArchive -archivePath app.xcarchive -exportPath app.ipa -exportOptionsPlist exportOptions.plist -allowProvisioningUpdates

cp "app.ipa/App Thinning Size Report.txt" .
