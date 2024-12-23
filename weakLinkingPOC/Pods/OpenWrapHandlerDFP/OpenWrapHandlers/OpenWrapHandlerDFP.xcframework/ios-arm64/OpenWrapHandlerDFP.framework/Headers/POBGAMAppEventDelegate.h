/*
 * PubMatic Inc. ("PubMatic") CONFIDENTIAL
 * Unpublished Copyright (c) 2006-2024 PubMatic, All Rights Reserved.
 *
 * NOTICE:  All information contained herein is, and remains the property of
 * PubMatic. The intellectual and technical concepts contained herein are
 * proprietary to PubMatic and may be covered by U.S. and Foreign Patents,
 * patents in process, and are protected by trade secret or copyright law.
 * Dissemination of this information or reproduction of this material is
 * strictly forbidden unless prior written permission is obtained from PubMatic.
 * Access to the source code contained herein is hereby forbidden to anyone
 * except current PubMatic employees, managers or contractors who have executed
 * Confidentiality and Non-disclosure agreements explicitly covering such access
 * or to such other persons whom are directly authorized by PubMatic to access
 * the source code and are subject to confidentiality and nondisclosure
 * obligations with respect to the source code.
 *
 * The copyright notice above does not evidence any actual or intended
 * publication or disclosure  of  this source code, which includes information
 * that is confidential and/or proprietary, and is a trade secret, of  PubMatic.
 * ANY REPRODUCTION, MODIFICATION, DISTRIBUTION, PUBLIC  PERFORMANCE, OR PUBLIC
 * DISPLAY OF OR THROUGH USE  OF THIS  SOURCE CODE  WITHOUT  THE EXPRESS WRITTEN
 * CONSENT OF PUBMATIC IS STRICTLY PROHIBITED, AND IN VIOLATION OF APPLICABLE
 * LAWS AND INTERNATIONAL TREATIES.  THE RECEIPT OR POSSESSION OF  THIS SOURCE
 * CODE AND/OR RELATED INFORMATION DOES NOT CONVEY OR IMPLY ANY RIGHTS TO
 * REPRODUCE, DISCLOSE OR DISTRIBUTE ITS CONTENTS, OR TO MANUFACTURE, USE, OR
 * SELL ANYTHING THAT IT  MAY DESCRIBE, IN WHOLE OR IN PART.
 */
#import <Foundation/Foundation.h>
#import <OpenWrapSDK/POBBannerEvent.h>
#import <OpenWrapSDK/POBInterstitialEvent.h>
#import <GoogleMobileAds/GoogleMobileAds.h>
/**
 ------------------------------------------------------------------------------------
 POBGAMAppEventDelegate Protocol
 ------------------------------------------------------------------------------------
 */

/*!
 This protocol is used to provide GAM app event from event handler
*/
@protocol POBGAMAppEventDelegate <NSObject>
@optional

/*!
 @abstract This method is called to notify GAM's banner app event.
 @param eventHandler associated banner event handler instance
 @param banner associated GAM banner view
 @param name app event name
 @param info app event info
 */
- (void)eventHandler:(id<POBBannerEvent>_Nonnull)eventHandler
          bannerView:(GAMBannerView *_Nonnull)banner
  didReceiveAppEvent:(NSString *_Nonnull)name
            withInfo:(NSString *_Nullable)info;

/*!
 @abstract This method is called to notify GAM's interstitial app event.
 @param eventHandler associated interstitial event handler instance
 @param interstitial associated GAM interstitial instance
 @param name app event name
 @param info app event info
 */
- (void)eventHandler:(id<POBInterstitialEvent>_Nonnull)eventHandler
        interstitial:(GAMInterstitialAd *_Nonnull)interstitial
  didReceiveAppEvent:(NSString *_Nonnull)name
            withInfo:(NSString *_Nullable)info;

@end
