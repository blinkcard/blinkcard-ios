//
//  MBException.h
//  Pdf417MobiDev
//
//  Created by Jura Skrlec on 07/02/2018.
//

#ifndef MBException_h
#define MBException_h

typedef NSString * MBCExceptionName NS_EXTENSIBLE_STRING_ENUM;

FOUNDATION_EXPORT MBCExceptionName const MBCIllegalModificationException;
FOUNDATION_EXPORT MBCExceptionName const MBCInvalidLicenseKeyException;
FOUNDATION_EXPORT MBCExceptionName const MBCInvalidLicenseeKeyException;
FOUNDATION_EXPORT MBCExceptionName const MBCInvalidLicenseResourceException;
FOUNDATION_EXPORT MBCExceptionName const MBCInvalidBundleException;
FOUNDATION_EXPORT MBCExceptionName const MBCMissingSettingsException;
FOUNDATION_EXPORT MBCExceptionName const MBCInvalidArgumentException;

#endif /* MBException_h */
