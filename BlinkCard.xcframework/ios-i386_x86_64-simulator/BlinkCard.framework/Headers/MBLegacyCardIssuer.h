//
//  MBPaymentLegacyCardIssuer.h
//  MicroBlink
//
//  Created by Jura on 07/02/2019.
//

#ifndef MBLegacyCardIssuer_h
#define MBLegacyCardIssuer_h

typedef NS_ENUM(NSInteger, MBCLegacyCardIssuer) {
    /* Unidentified Card */
    MBCLegacyCardIssuerOther = 0,
    /* The American Express Company Card */
    MBCLegacyCardIssuerAmericanExpress,
    /* The Bank of Montreal ABM Card */
    MBCLegacyCardIssuerBmoAbm,
    /* China T-Union Transportation Card */
    MBCLegacyCardIssuerChinaTUnion,
    /* China UnionPay Card */
    MBCLegacyCardIssuerChinaUnionPay,
    /* Canadian Imperial Bank of Commerce Advantage Debit Card */
    MBCLegacyCardIssuerCibcAdvantageDebit,
    /* CISS Card */
    MBCLegacyCardIssuerCiss,
    /* Diners Club International Card */
    MBCLegacyCardIssuerDinersClubInternational,
    /* Diners Club United States & Canada Card */
    MBCLegacyCardIssuerDinersClubUsCanada,
    /* Discover Card */
    MBCLegacyCardIssuerDiscoverCard,
    /* HSBC Bank Canada Card */
    MBCLegacyCardIssuerHsbc,
    /* RuPay Card */
    MBCLegacyCardIssuerRuPay,
    /* InterPayment Card */
    MBCLegacyCardIssuerInterPayment,
    /* InstaPayment Card */
    MBCLegacyCardIssuerInstaPayment,
    /* The JCB Company Card */
    MBCLegacyCardIssuerJcb,
    /* Laser Debit Card (deprecated) */
    MBCLegacyCardIssuerLaser,
    /* Maestro Debit Card */
    MBCLegacyCardIssuerMaestro,
    /* Dankort Card */
    MBCLegacyCardIssuerDankort,
    /* MIR Card */
    MBCLegacyCardIssuerMir,
    /* MasterCard Inc. Card */
    MBCLegacyCardIssuerMasterCard,
    /* The Royal Bank of Canada Client Card */
    MBCLegacyCardIssuerRbcClient,
    /* ScotiaBank Scotia Card */
    MBCLegacyCardIssuerScotiaBank,
    /* TD Canada Trust Access Card */
    MBCLegacyCardIssuerTdCtAccess,
    /* Troy Card */
    MBCLegacyCardIssuerTroy,
    /* Visa Inc. Card */
    MBCLegacyCardIssuerVisa,
    /* Universal Air Travel Plan Inc. Card */
    MBCLegacyCardIssuerUatp,
    /* Interswitch Verve Card */
    MBCLegacyCardIssuerVerve
};

#endif /* MBPaymentLegacyCardIssuer_h */
