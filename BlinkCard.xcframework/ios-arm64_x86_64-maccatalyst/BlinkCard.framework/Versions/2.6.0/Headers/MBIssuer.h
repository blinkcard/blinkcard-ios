//
//  MBIssuer.h
//  BlinkShowcaseDev
//
//  Created by Jura Skrlec on 02/11/2020.
//

#ifndef MBIssuer_h
#define MBIssuer_h

typedef NS_ENUM(NSInteger, MBCIssuer) {
    /* Unidentified Card */
    MBCIssuerOther = 0,
    /* The American Express Company Card */
    MBCIssuerAmericanExpress,
    /* China UnionPay Card */
    MBCIssuerChinaUnionPay,
    /* Diners Club International Card */
    MBCIssuerDiners,
    /* Discover Card */
    MBCIssuerDiscoverCard,
    /* Elo card association */
    MBCIssuerElo,
    /* The JCB Company Card */
    MBCIssuerJcb,
    /* Maestro Debit Card */
    MBCIssuerMaestro,
    /* Mastercard Inc. Card */
    MBCIssuerMastercard,
    /* RuPay */
    MBCIssuerRuPay,
    /* Interswitch Verve Card */
    MBCIssuerVerve,
    /* Visa Inc. Card */
    MBCIssuerVisa,
    /* VPay */
    MBCIssuerVPay
};

#endif /* MBIssuer_h */
