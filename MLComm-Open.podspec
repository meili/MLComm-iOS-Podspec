
Pod::Spec.new do |s|

  s.name         = "MLComm-Open"
  s.version      = "0.0.5.1"
  s.summary      = "meili wireless common components."

  s.description  = <<-DESC
  meili wireless common components. All in one.
                   DESC

  s.homepage     = "http://github.com/meili/MLComm-iOS-Podspec"

  s.license      = { :type => "MIT", :file => "LICENSE" }

  s.author             = { "mogujie" => "mopen@meili-inc.com" }

  s.platform     = :ios
  s.platform     = :ios, "8.0"

  #  When using multiple platforms
  s.ios.deployment_target = "8.0"
  # s.osx.deployment_target = "10.7"
  # s.watchos.deployment_target = "2.0"
  # s.tvos.deployment_target = "9.0"

  # s.source = { :http => 'http://s3.mogucdn.com/mlcdn/c45406/1529393549396_MLComm.framework.zip' }
    s.source       = { :git => "https://github.com/meili/MLComm-iOS-Podspec.git", :tag => "#{s.version}" }

  s.default_subspecs = 'WTPipelineForOC', 'iOS_Util_Json','MGJURLTokenGenerator','MGJ-Categories','MGJLogger','MGJConcurrentContainers','MGJMacros'

  s.subspec '__default__' do |ss|
    ss.vendored_libraries = 'libMLComm.a'
  end

  s.subspec 'WTPipelineForOC' do |ss|
    ss.header_mappings_dir = 'MLComm/Classes'
    ss.public_header_files = 'MLComm/Classes/WTPipelineForOC/**/*.h'
    ss.source_files = 'MLComm/Classes/WTPipelineForOC/**/*'
    ss.dependency 'MLComm-Open/__default__'
  end

  s.subspec 'iOS_Util_Json' do |ss|
    ss.header_mappings_dir = 'MLComm/Classes'
    ss.public_header_files = 'MLComm/Classes/iOS_Util_Json/**/*.h'
    ss.source_files = 'MLComm/Classes/iOS_Util_Json/**/*'
    ss.dependency 'MLComm-Open/__default__'
  end

  s.subspec 'MGJURLTokenGenerator' do |ss|
    ss.header_mappings_dir = 'MLComm/Classes'
    ss.public_header_files = 'MLComm/Classes/MGJURLTokenGenerator/**/*.h'
    ss.source_files = 'MLComm/Classes/MGJURLTokenGenerator/**/*'
    ss.vendored_libraries = 'MLComm/Classes/MGJURLTokenGenerator/libMGJURLToken.a'
    ss.dependency 'MLComm-Open/__default__'
  end

  s.subspec 'MGJ-Categories' do |ss|
    ss.header_mappings_dir = 'MLComm/Classes'
    ss.public_header_files = 'MLComm/Classes/MGJ-Categories/**/*.h'
    ss.source_files = 'MLComm/Classes/MGJ-Categories/**/*'
    ss.dependency 'SAMKeychain'
    ss.dependency 'AFNetworking/Reachability'
    ss.dependency 'MLComm-Open/__default__'
    ss.frameworks = 'SystemConfiguration','AdSupport','CoreTelephony'
  end

  s.subspec 'MGJLogger' do |ss|
    ss.header_mappings_dir = 'MLComm/Classes'
    ss.public_header_files = 'MLComm/Classes/MGJLogger/**/*.h'
    ss.source_files = 'MLComm/Classes/MGJLogger/**/*'
    ss.dependency 'MLComm-Open/__default__'
  end

  s.subspec 'MGJConcurrentContainers' do |ss|
    ss.header_mappings_dir = 'MLComm/Classes'
    ss.public_header_files = 'MLComm/Classes/MGJConcurrentContainers/**/*.h'
    ss.source_files = 'MLComm/Classes/MGJConcurrentContainers/**/*'
    ss.dependency 'MLComm-Open/__default__'
  end

  s.subspec 'MGJMacros' do |ss|
    ss.header_mappings_dir = 'MLComm/Classes'
    ss.public_header_files = 'MLComm/Classes/MGJMacros/**/*.h'
    ss.source_files = 'MLComm/Classes/MGJMacros/**/*'
    ss.dependency 'libextobjc'
    ss.dependency 'MLComm-Open/__default__'
  end
end
