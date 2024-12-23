Pod::Spec.new do |s|
  s.version = '1.0.0'
  s.name             = "WeakLinkingPOCSDK"
  s.summary          = 'SDK iOS SDK'
  s.description      = 'The iOS implementation of SDK'
  s.swift_version = '5.0'
  s.license          = { :type => 'Copyright' }
  s.author           = 'OpenWeb'
  s.platform        = :ios
  s.homepage         = 'https://bitbucket.org/aniviewteam/spotim-sdk-kmm'
  s.source           = { :git => "git@bitbucket.org:aniviewteam/spotim-sdk-kmm.git"}
  s.ios.deployment_target = '13.0'
  s.module_name = "weakLinkingPOCSDK"

  s.source_files = "weakLinkingPOCSDK/**/*"

#  s.vendored_frameworks = "Release/weakLinkingPOCSDK.xcframework"

#s.subspec 'Core' do |ss|
#  ss.vendored_frameworks = "Release/weakLinkingPOCSDK.xcframework"
#  ss.dependency 'WeakLinkingPOCSDK/SourcesSDK'
#end
#
#s.subspec 'SourcesSDK' do |ss|
#  ss.source_files = "SourcesSDK/**/*"
#  ss.xcconfig = {
#      'FRAMEWORK_SEARCH_PATHS' => "$(inherited) ${PODS_ROOT}../../OptionalFramework/Release/OptionalFrameworkSDK.xcframework ${PODS_XCFRAMEWORKS_BUILD_DIR}/OptionalFrameworkSDK"
#  }
#end


  s.dependency 'AlonSourcesSDK'

#s.pod_target_xcconfig = {
#  'FRAMEWORK_SEARCH_PATHS' => "$(inherited) ${PODS_CONFIGURATION_BUILD_DIR}/AlonSourcesSDK"
#}
end
