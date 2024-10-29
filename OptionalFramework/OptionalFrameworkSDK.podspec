Pod::Spec.new do |s|
  s.version = '1.0.0'
  moduleName = 'OptionalFrameworkSDK'
  s.name             = "OptionalFrameworkSDK"
  s.summary          = 'SDK iOS OptionalFrameworkSDK'
  s.description      = 'The iOS implementation of SourcesSDK'
  s.swift_version = '5.0'
  s.license          = { :type => 'Copyright' }
  s.author           = 'OpenWeb'
  s.platform        = :ios
  s.homepage         = 'https://bitbucket.org/aniviewteam/spotim-sdk-kmm'
  s.source           = { :git => "git@bitbucket.org:aniviewteam/spotim-sdk-kmm.git"}
  s.ios.deployment_target = '13.0'
  s.static_framework = true

  s.vendored_frameworks = "Release/OptionalFrameworkSDK.xcframework"
end

