//
//  SDK.swift
//  weakLinkingPOCSDK
//
//  Created by Alon Shprung on 25/09/2024.
//

import Foundation
import UIKit
import AlonSourcesSDK

public class SDK {

    private init() {
    }

    public static var shared = SDK()


    public func test() {
        print("SDK test called!")

        SourcesClass.test()
    }

    public var monetization: OWMonitization = OWMonitizationLayer()

    public func ad(params: AdParamsProtocolBridge) -> UIView {
        return SourcesClass.ad(params: params)
    }
}
