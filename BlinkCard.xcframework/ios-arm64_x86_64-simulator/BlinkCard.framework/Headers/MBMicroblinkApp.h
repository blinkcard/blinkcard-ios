//
//  App.h
//  iphone-photopay
//
//  Created by Ja on 11/2/11.
//  Copyright (c) 2011 jcerovec@gmail.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"

#ifdef __OBJC__
#import <UIKit/UIKit.h>
#endif

#define PP_IS_IPAD (([UIDevice currentDevice].userInterfaceIdiom == UIUserInterfaceIdiomPad))

#define PP_NOTIFY(notificationKey, valueKey)                                                                  \
    {                                                                                                         \
        NSDictionary *dict = [NSDictionary dictionaryWithObject:@(YES) forKey:valueKey];                      \
        [[NSNotificationCenter defaultCenter] postNotificationName:notificationKey object:nil userInfo:dict]; \
    }

MB_CLASS_AVAILABLE_IOS(13.0)
@interface MBCMicroblinkApp : NSObject

@property (nonatomic) NSString *language;

/** Bundle with resources used in framework */
@property (nonatomic) NSBundle *resourcesBundle;

/** Custom bundle for overriding resourcesBundle */
@property (nonatomic) NSBundle *customResourcesBundle;

/** Localization file in main bundle used for overrideing framework's localizations */
@property (nonatomic) NSString *customLocalizationFileName;

/** Obtain the shared instance */
+ (instancetype)sharedInstance NS_SWIFT_NAME(shared());

/** Sets the language used in PhotoPaySDK */
- (void)setLanguage:(NSString *)language;

/** Sets the language to default (i.e. language specified in the user's device settings */
- (void)setDefaultLanguage;

/** Pushes the UIApplication status bar style to a internally handled stack */
- (void)pushStatusBarStyle:(UIStatusBarStyle)statusBarStyle;

/** Returns the status bar style to the last saved value */
- (void)popStatusBarStyle;

/** Push the status bar hidden value */
- (void)pushStatusBarHidden:(BOOL)hidden;

/** pops the status bar hidden value */
- (void)popStatusBarHidden;

/** Sets the key that the help was shown to true */
- (void)setHelpShown:(BOOL)value;

/** Returns true if the help was already shown */
- (BOOL)isHelpShown;

/**
 * Returns the default resources bundle. If it doesn't exist, it will be nil.
 */
+ (NSBundle *)getDefaultResourcesBundle;

@end


// MARK: - Localization

static inline NSString * MBC_LOCALIZED_DEFAULT_STRING(NSString *key) {
    return ([NSString stringWithFormat:@"[[%@]]", key]);
}

static inline NSString * MBC_LOCALIZED_FOR_LANGUAGE(NSString *key, NSString *language) {

    NSString *overridenStringFromCustomBundle = NSLocalizedStringWithDefaultValue(key,
                                                                                  language,
                                                                                  [MBCMicroblinkApp sharedInstance].customResourcesBundle,
                                                                                  @"",
                                                                                  @"");
    if ( overridenStringFromCustomBundle != nil && ![overridenStringFromCustomBundle isEqualToString:key]) {
        return overridenStringFromCustomBundle;
    }

    return NSLocalizedStringWithDefaultValue(key,
                                             language,
                                             [MBCMicroblinkApp sharedInstance].resourcesBundle,
                                             MBC_LOCALIZED_DEFAULT_STRING(key),
                                             nil);
}

static inline NSString * MBC_LOCALIZED(NSString *key) {
    NSString *localizationFileName = [MBCMicroblinkApp sharedInstance].customLocalizationFileName;
    if (localizationFileName) {
        NSString *overridenStringFromCustomLocalizationFile = NSLocalizedStringWithDefaultValue(key, localizationFileName, [NSBundle mainBundle], @"", @"");

        if (![overridenStringFromCustomLocalizationFile isEqualToString:key]) {
            return overridenStringFromCustomLocalizationFile;
        }
    }
    
    NSString *language = [MBCMicroblinkApp sharedInstance].language;
    NSString *localizedString = MBC_LOCALIZED_FOR_LANGUAGE(key, language);
    
#if DEBUG
    return localizedString;
#else
    if ([localizedString isEqualToString:MBC_LOCALIZED_DEFAULT_STRING(key)]) {
        if (![language isEqualToString:@"ar-AE"] && [language hasPrefix:@"ar"]) {
            localizedString = MBC_LOCALIZED_FOR_LANGUAGE(key, @"ar-AE");
        }
        else if (![language isEqualToString:@"en"]) {
            localizedString = MBC_LOCALIZED_FOR_LANGUAGE(key, @"en");
        }
    }
    return localizedString;
#endif
}
