//
//  OptionalSDK.swift
//  OptionalFrameworkSDK
//
//  Created by Alon Shprung on 30/09/2024.
//

import Foundation
import UIKit

public class OptionalSDK {
    private init() {}

    public static var shared = OptionalSDK()

    public func doOptionalThing() {
        print("OptionalSDK - doOptionalThing called!")
    }

    public func returnOptionalStruct() -> OptionalSDKStruct {
        return OptionalSDKStruct(a: "a", b: 1)
    }

    public func ad(params: AdParamsProtocol) -> UIView {
        return UIView()
    }
}
