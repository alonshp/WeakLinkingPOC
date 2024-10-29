//
//  ViewController.swift
//  weakLinkingPOC
//
//  Created by Alon Shprung on 25/09/2024.
//

import UIKit
import weakLinkingPOCSDK

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.

    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)

        SDK.shared.test()
//        SourcesClass().test()
    }
}

