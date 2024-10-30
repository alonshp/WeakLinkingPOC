//
//  ViewController.swift
//  TestWeakSPM
//
//  Created by Alon Shprung on 30/10/2024.
//

import UIKit
import weakLinkingPOCSDK
//import AlonSourcesSDK

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.

        SDK.shared.test()
//        SourcesClass.test()
//        OWMonitizationLayer()
    }


}

