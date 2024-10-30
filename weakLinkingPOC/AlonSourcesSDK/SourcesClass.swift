//
//  SourcesClass.swift
//  SourcesClass
//
//  Created by Alon Shprung on 30/09/2024.
//

import Foundation
@_exported import UIKit

#if canImport(OptionalFrameworkSDK)
@_exported import OptionalFrameworkSDK
#endif

#if canImport(OptionalFrameworkSDK)
public protocol OWMonitization {
    func foo()
}
#else
public protocol OWMonitization {

}
#endif

#if canImport(OptionalFrameworkSDK)
public struct OWMonitizationLayer: OWMonitization {
    public init() {

    }
    public func foo() {
        print("OWMonitizationLayer foo called!")
    }
}
#else
public struct OWMonitizationLayer: OWMonitization {
    public init() {

    }
}
#endif

public class SourcesClass {

    public init() {}

    public static func test() {
        print("SourcesClass test called!")

        #if canImport(OptionalFrameworkSDK)
        OptionalSDK.shared.doOptionalThing()
        #endif
    }

    public static func ad(params: AdParamsProtocolBridge) -> UIView {
        #if canImport(OptionalFrameworkSDK)
        let adParams: AdParamsProtocol = AdParams(
            a: params.a,
            b: params.b
        )
        print("SourcesClass ad return OptionalSDK view!")
        return OptionalSDK.shared.ad(params: adParams)
        #else
        print("SourcesClass ad return empty view!")
        return UIView()
        #endif
    }
}
