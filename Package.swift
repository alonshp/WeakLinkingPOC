// swift-tools-version:5.5
import PackageDescription

func createProducts() -> [Product] {
    let products: [Product] = [
			.library(name: "AlonSDK", targets: ["SDKWrapperTarget"]),
			.library(name: "AlonSourcesSDK", targets: ["AlonSourcesSDK"])
		]

    return products
}

func createTargets() -> [Target] {
    var targets = [Target]()

    // Adding MainSDK xcframework
    let MainSDK: Target = .binaryTarget(
        name: "AlonSDK",
        path: "weakLinkingPOC/Release/weakLinkingPOCSDK.xcframework"
    )
    targets.append(MainSDK)

let SourcesTarget: Target = .target(
        name: "AlonSourcesSDK",
        path: "weakLinkingPOC/AlonSourcesSDK"
    )
    targets.append(SourcesTarget)

// Adding a "wrapper" target which all xcframeworks are "dependencies" to this one
    let wrapperTarget: Target = .target(
        name: "SDKWrapperTarget",
        dependencies: [
            .target(name: "AlonSDK", condition: .when(platforms: .some([.iOS]))),
	.target(name: "AlonSourcesSDK", condition: .when(platforms: .some([.iOS]))),
        ],
        path: "SDKWrapperTarget",
	    linkerSettings: [
        	.linkedFramework("AlonSourcesSDK")
	]
    )
    targets.append(wrapperTarget)

	return targets
}

let products = createProducts()
let targets = createTargets()

let package = Package(
    name: "AlonSDK",
    platforms: [
        .iOS(.v12)
    ],
    products: products,
	dependencies: [
        // Declare the AlonSourcesSDK package dependency here
    ],
    targets: targets
)
