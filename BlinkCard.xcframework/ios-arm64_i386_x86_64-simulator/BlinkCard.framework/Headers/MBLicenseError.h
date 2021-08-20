//
//  MBLicenseError.h
//  MicroblinkDev
//
//  Created by Mijo Gracanin on 23/09/2020.
//

#ifndef MBLicenseError_h
#define MBLicenseError_h

#import <Foundation/Foundation.h>

extern NSString * const MBCLicenseErrorNotification;

typedef NS_ENUM(NSInteger, MBCLicenseError) {
    MBCLicenseErrorNetworkRequired,
    MBCLicenseErrorUnableToDoRemoteLicenceCheck,
    MBCLicenseErrorLicenseIsLocked,
    MBCLicenseErrorLicenseCheckFailed,
    MBCLicenseErrorInvalidLicense,
    MBCLicenseErrorPermissionExpired,
    MBCLicenseErrorPayloadCorrupted,
    MBCLicenseErrorPayloadSignatureVerificationFailed,
    MBCLicenseErrorIncorrectTokenState
};

typedef void(^MBCLicenseErrorBlock)(MBCLicenseError licenseError);

#endif /* MBLicenseError_h */
