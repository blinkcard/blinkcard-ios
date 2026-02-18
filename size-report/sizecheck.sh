#!/bin/sh

xcodebuild -project Samples/DownloadResources/BlinkCardSample/BlinkCardSample.xcodeproj -sdk iphoneos archive -archivePath size-report/app.xcarchive -scheme BlinkCardSample

xcodebuild -exportArchive -archivePath size-report/app.xcarchive -exportPath size-report/app.ipa -exportOptionsPlist size-report/exportOptions.plist -allowProvisioningUpdates

cp "size-report/app.ipa/App Thinning Size Report.txt" "size-report"
