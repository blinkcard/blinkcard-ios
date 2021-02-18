#!/bin/sh
set -e

xcodebuild -project Samples/BlinkCard-Sample-ObjC/BlinkCard-Sample-ObjC.xcodeproj \
    -scheme BlinkCard-Sample-ObjC \
    -configuration Debug \
    -sdk iphonesimulator \
    ONLY_ACTIVE_ARCH=NO \
    clean build

xcodebuild -project Samples/BlinkCard-Sample-ObjC/BlinkCard-Sample-ObjC.xcodeproj \
    -scheme BlinkCard-Sample-ObjC \
    -configuration Release \
    -sdk iphonesimulator \
    ONLY_ACTIVE_ARCH=NO \
    clean build

 xcodebuild -project Samples/BlinkCard-sample-Swift/BlinkCard-sample-Swift.xcodeproj \
    -scheme BlinkCard-sample-Swift \
    -configuration Debug \
    -sdk iphonesimulator \
    ONLY_ACTIVE_ARCH=NO \
    clean build

xcodebuild -project Samples/BlinkCard-sample-Swift/BlinkCard-sample-Swift.xcodeproj \
    -scheme BlinkCard-sample-Swift \
    -configuration Release \
    -sdk iphonesimulator \
    ONLY_ACTIVE_ARCH=NO \
    clean build    
