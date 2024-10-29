//
//  ViewController.swift
//  TestWeakLinking
//
//  Created by Alon Shprung on 25/09/2024.
//

import UIKit
import weakLinkingPOCSDK


class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
//        SDK.shared.monetization.foo()
        SDK.shared.test()
//        SourcesClass.test()
//        let a = OptionalSDK.shared.returnOptionalStruct()
//        print(a)
//        _ = SDK.shared.ad(params: AdParamsBridge(a: "", b: 1))
    }
}

