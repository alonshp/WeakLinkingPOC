/*
* PubMatic Inc. ("PubMatic") CONFIDENTIAL
* Unpublished Copyright (c) 2006-2024 PubMatic, All Rights Reserved.
*
* NOTICE:  All information contained herein is, and remains the property of PubMatic. The intellectual and technical concepts contained
* herein are proprietary to PubMatic and may be covered by U.S. and Foreign Patents, patents in process, and are protected by trade secret or copyright law.
* Dissemination of this information or reproduction of this material is strictly forbidden unless prior written permission is obtained
* from PubMatic.  Access to the source code contained herein is hereby forbidden to anyone except current PubMatic employees, managers or contractors who have executed
* Confidentiality and Non-disclosure agreements explicitly covering such access or to such other persons whom are directly authorized by PubMatic to access the source code and are subject to confidentiality and nondisclosure obligations with respect to the source code.
*
* The copyright notice above does not evidence any actual or intended publication or disclosure  of  this source code, which includes
* information that is confidential and/or proprietary, and is a trade secret, of  PubMatic.   ANY REPRODUCTION, MODIFICATION, DISTRIBUTION, PUBLIC  PERFORMANCE,
* OR PUBLIC DISPLAY OF OR THROUGH USE  OF THIS  SOURCE CODE  WITHOUT  THE EXPRESS WRITTEN CONSENT OF PUBMATIC IS STRICTLY PROHIBITED, AND IN VIOLATION OF APPLICABLE
* LAWS AND INTERNATIONAL TREATIES.  THE RECEIPT OR POSSESSION OF  THIS SOURCE CODE AND/OR RELATED INFORMATION DOES NOT CONVEY OR IMPLY ANY RIGHTS
* TO REPRODUCE, DISCLOSE OR DISTRIBUTE ITS CONTENTS, OR TO MANUFACTURE, USE, OR SELL ANYTHING THAT IT  MAY DESCRIBE, IN WHOLE OR IN PART.
*/

#import <OpenWrapSDK/POBBannerEvent.h>
#import <GoogleMobileAds/GoogleMobileAds.h>
#import "POBGAMAppEventDelegate.h"

NS_ASSUME_NONNULL_BEGIN
/*!
 GAM native configuration block having GAMRequest, POBBid as parameters
 */
typedef void(^GAMNativeBannerConfigBlock)(GAMRequest * request, POBBid *bid);

/**
 ------------------------------------------------------------------------------------
 POBGAMNativeAdDelegate Protocol
 ------------------------------------------------------------------------------------
 */

/*!
 Protocol for interaction with the GAM's native ad instance.
*/
@protocol POBGAMNativeAdDelegate <NSObject>
/*!
 @abstract Notifies the delegate that an ad has been successfully received.
 @param eventHandler Instance of GAMNativeEventHandler
 @param nativeAd The GADNativeAd instance sending the message.
 */
- (void)eventHandler:(id<POBBannerEvent>)eventHandler didReceiveNativeAd:(GADNativeAd *)nativeAd;
@end

/**
 ------------------------------------------------------------------------------------
 POBGAMCustomNativeAdDelegate Protocol
 ------------------------------------------------------------------------------------
 */

/*!
 Protocol for the interaction with GAM's custom native ad instance.
*/
@protocol POBGAMCustomNativeAdDelegate <NSObject>
/*!
 @abstract Method to return an array of custom native ad format ID
 @return List of strings
 */
- (NSArray<NSString *> *)customNativeAdFormatIDs;

/*!
 @abstract Notifies the delegate that an ad has been successfully received.
 @param eventHandler Instance of GAMNativeEventHandler
 @param customNativeAd The GADCustomNativeAd instance sending the message.
 */
- (void)eventHandler:(id<POBBannerEvent>)eventHandler didReceiveCustomNativeAd:(GADCustomNativeAd *)customNativeAd;
@end

/*!
 This class manages GAM's Native + Banner combined header bidding requests using AdLoader and listens to the respective callbacks.
 It also communicates with the OpenWrap SDK, via POBBannerEvent delegate, to inform the GAM banner ad events.
 Native/custom native ad callbacks are provided through specific delegates POBGAMNativeAdDelegate or POBGAMCustomNativeAdDelegate, while banner ad events are provided through POBBannerViewDelegate as usual.
 Note: You must set up banner demand, in addition to native and/or custom native, to include OW banner bids
 Reference: https://developers.google.com/ad-manager/mobile-ads-sdk/ios/native-banner
 */
@interface GAMNativeBannerEventHandler : NSObject<POBBannerEvent>

/*!
 Initializes and returns a event handler with the specified GAM ad unit and banner ad sizes
 
 @param adUnitId GAM ad unit id
 @param adTypes  An array of GADAdLoaderAdType
 @param options An array of GADAdLoaderOptions objects to configure how ads are loaded, or nil to use default options
 @param validSizes Array of NSValue encoded GADAdSize structs. Never create your own GADAdSize directly. Use one of the predefined
 standard ad sizes (such as GADAdSizeBanner), or create one using the GADAdSizeFromCGSize
 method.
 Example:
 <pre>
 NSArray *validSizes = @[
 NSValueFromGADAdSize(GADAdSizeBanner),
 NSValueFromGADAdSize(GADAdSizeLargeBanner)
 ];
 bannerView.validAdSizes = validSizes;
 </pre>
 @return Instance of GAMNativeEventHandler
 */
- (instancetype)initWithAdUnitId:(NSString *)adUnitId
                         adTypes:(nonnull NSArray<GADAdLoaderAdType> *)adTypes
                         options:(nullable NSArray<GADAdLoaderOptions *> *)options
                        andSizes:(NSArray<NSValue *> *)validSizes;

/*!
 @abstract Delegate object conforming to POBGAMNativeAdDelegate protocol
 */
@property (nonatomic, weak) id<POBGAMNativeAdDelegate> nativeDelegate;

/*!
 @abstract Delegate object conforming to POBGAMCustomNativeAdDelegate protocol
 */
@property (nonatomic, weak) id<POBGAMCustomNativeAdDelegate> customNativeDelegate;

/*!
 A configBlock that is called before event handler makes ad request call to GAM SDK. It passes GAMRequest which will be used to make ad request.
 */
@property (nonatomic, copy) GAMNativeBannerConfigBlock configBlock;

/*!
 Delegate object which is used to provide GAM app event callback
 */
@property (nonatomic, weak) id<POBGAMAppEventDelegate> appEventDelegate;
@end

NS_ASSUME_NONNULL_END
