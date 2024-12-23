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
#import <Foundation/Foundation.h>
#import <OpenWrapSDK/POBNativeAdEvent.h>
#import <GoogleMobileAds/GoogleMobileAds.h>

NS_ASSUME_NONNULL_BEGIN
/*!
 @abstract GAM native configuration block having GAMRequest, POBBid as parameters
 */
typedef void(^GAMNativeAdConfigBlock)(GAMRequest * request, POBBid *bid);

/*!
 @abstract GAM native ad rendering block.
 */
typedef GADNativeAdView*_Nullable(^GAMNativeAdRenderingBlock)(GADNativeAd * nativeAd);

/*!
 @abstract GAM's custom native ad rendering block.
 */
typedef UIView*_Nullable(^GAMCustomNativeAdRenderingBlock)(GADCustomNativeAd * customNativeAd);

/**
 ------------------------------------------------------------------------------------
 GAMNativeEventHandler class
 ------------------------------------------------------------------------------------
 */
/*!
 @abstract This class manages communication between GAM & OpenWrap SDK. Native/custom native ad events are managed internally and are provided via POBNativeAdDelegate.
 */
@interface GAMNativeEventHandler : NSObject<POBNativeAdEvent>
/*!
 @abstract Initializes and returns a event handler with the specified GAM ad unit
 @param adUnitId GAM ad unit id
 @param adTypes  An array of GADAdLoaderAdType
 @param options An array of GADAdLoaderOptions objects to configure how ads are loaded, or nil to use default options
 @param owFormatId Native format Id for OpenWrap's custom native ad format
 @return Instance of GAMNativeEventHandler
 */
- (instancetype)initWithAdUnitId:(NSString *)adUnitId
                         adTypes:(nonnull NSArray<GADAdLoaderAdType> *)adTypes
                         options:(nullable NSArray<GADAdLoaderOptions *> *)options
                      owFormatId:(NSString *)owFormatId;

/*!
 @abstract A configBlock that is called before event handler makes ad request call to GAM SDK. It passes GAMRequest which will be used to make ad request.
 */
@property (nonatomic, copy) GAMNativeAdConfigBlock configBlock;

/*!
 @abstract A config block to get the GAM's native ad view rendered by publisher.
 */
@property (nonatomic, copy) GAMNativeAdRenderingBlock nativeRenderingBlock;

/*!
 @abstract A config block to get the GAM's custom native ad view rendered by publisher.
 */
@property (nonatomic, copy) GAMCustomNativeAdRenderingBlock customNativeRenderingBlock;

/*!
 @abstract Format Ids required for rendering GAM's custom native format.
 */
@property (nonatomic, strong) NSArray<NSString *> *formatIds;

@end

NS_ASSUME_NONNULL_END
