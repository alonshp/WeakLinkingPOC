//
//  AdParamsBridge.swift
//  SourcesSDK
//
//  Created by Alon Shprung on 09/10/2024.
//

import Foundation

public protocol AdParamsProtocolBridge {
    var a: String { get }
    var b: Int { get }
}

public struct AdParamsBridge: AdParamsProtocolBridge {
    public var a: String
    public var b: Int

    public init(a: String, b: Int) {
        self.a = a
        self.b = b
    }
}
