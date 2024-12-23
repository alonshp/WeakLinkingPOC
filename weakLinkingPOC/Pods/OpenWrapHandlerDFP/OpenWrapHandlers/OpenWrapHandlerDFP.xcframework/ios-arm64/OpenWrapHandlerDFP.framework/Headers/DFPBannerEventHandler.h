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
#import "POBGAMAppEventDelegate.h"

@class GAMBannerView,GAMRequest;

/*!
 DFP banner configuration block having GAMBannerView, request as parameters
 */
typedef void(^DFPBannerConfigBlock)(GAMBannerView *view,GAMRequest * request,POBBid * bid);

/*!
 This class is responsible for communication between OpenWrap banner view and DFP banner view.
 It implements the POBBannerEvent protocol. it notifies event back to OpenWrap SDK using POBBannerEventDelegate methods
 */
@interface DFPBannerEventHandler : NSObject <POBBannerEvent>

/*!
 Initializes and returns a event handler with the specified DFP ad unit and ad sizes
 
 @param adUnitId DFP ad unit id
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
 */
- (instancetype)initWithAdUnitId:(NSString *)adUnitId
                        andSizes:(NSArray *)validSizes;

/*!
 @abstract Initializes and returns an event handler instance with GAM ad unit and ad size. Use this initializer to request adaptive sizes from GAM.
 @param adUnitId GAM ad unit id
 @param gamAdSize GADAdSize to be used for GAM ad request. You may also use an adaptive size here.
 @param owAdSizes Array of POBAdSizes to be used for OpenWrap ad request
 */
- (instancetype)initWithAdUnitId:(NSString *)adUnitId
                       gamAdSize:(GADAdSize)gamAdSize
                       owAdSizes:(NSArray<POBAdSize *> *)owAdSizes;

/*!
 @abstract Optional API to set valid ad sizes for the GAM ad request.
 Array of NSValue encoded GADAdSize structs. Never create your own GADAdSize directly. Use one of the predefined
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
 
 @param validGAMAdSizes array of GADAdSizes to be used for GAM ad request
 */
- (void)setValidGAMAdSizes:(NSArray<NSValue *> *)validGAMAdSizes;

/*!
 A configBlock that is called before event handler makes ad request call to DFP SDK. It passes GAMBannerView & GAMRequest which will be used to make ad request.
 */
@property (nonatomic, copy) DFPBannerConfigBlock configBlock;

/*!
 Delegate object which is used to provide GAM app event callback
 */
@property (nonatomic, weak) id<POBGAMAppEventDelegate> appEventDelegate;
@end
