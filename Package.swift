// swift-tools-version:5.5
import PackageDescription

func createProducts() -> [Product] {
    let products: [Product] = [
			.library(name: "AlonSDK", targets: [SDKWrapperTarget]),
			.library(name: "AlonSourcesSDK", targets: [SDKWrapperTarget])
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
        path: "weakLinkingPOC/SourcesSDK"
    )
    targets.append(SourcesTarget)

		// Adding a "wrapper" target which all xcframeworks are "dependencies" to this one
    let wrapperTarget: Target = .target(
        name: "SDKWrapperTarget",
        dependencies: [
            .target(name: "AlonSDK", condition: .when(platforms: .some([.iOS]))),
						.target(name: "AlonSourcesSDK", condition: .when(platforms: .some([.iOS])))
        ],
        path: "SDKWrapperTarget"
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
    targets: targets
)