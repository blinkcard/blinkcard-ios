//
//  MBDataMatchStatus.h
//  BlinkIDDev
//
//  Created by Mijo Gracanin on 25.10.2022..
//

#ifndef MBDataMatchStatus_h
#define MBDataMatchStatus_h

/**
* Result of the data matching algorithm for scanned parts/sides of the document.
**/
typedef NS_ENUM(NSInteger, MBCDataMatchState) {
    /** Data matching has not been performed. */
    MBCDataMatchStateNotPerformed = 0,
    /** Data does not match. */
    MBCDataMatchStateFailed,
    /** Data match. */
    MBCDataMatchStateSuccess
};

#endif /* MBDataMatchStatus_h */
