Pod::Spec.new do |s|
  s.version = '1.0.0'
  s.name             = "AlonSourcesSDK"
  s.summary          = 'SDK iOS SourcesSDK'
  s.description      = 'The iOS implementation of SourcesSDK'
  s.swift_version = '5.0'
  s.license          = { :type => 'Copyright' }
  s.author           = 'OpenWeb'
  s.platform        = :ios
  s.homepage         = 'https://bitbucket.org/aniviewteam/spotim-sdk-kmm'
  s.source           = { :git => "git@github.com:alonshp/WeakLinkingPOC.git"}
  s.ios.deployment_target = '13.0'

  s.source_files = "AlonSourcesSDK/**/*"

  # TODO - We will need to change the path
  s.pod_target_xcconfig = {
    'FRAMEWORK_SEARCH_PATHS' => "$(inherited) ${PODS_ROOT}../../OptionalFramework/Release/OptionalFrameworkSDK.xcframework ${PODS_XCFRAMEWORKS_BUILD_DIR}/OptionalFrameworkSDK"
  }
end
