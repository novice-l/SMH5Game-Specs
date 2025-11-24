Pod::Spec.new do |s|

  s.name             = 'SMH5Game'
  s.version          = '2.0.5'
  s.summary          = 'Play motion games with a gyroscope-enabled device on iOS'
  s.homepage         = 'https://github.com/novice-l/SMH5Game-Specs'
  s.license = { :type => 'Copyright', :text => <<-LICENSE
    Copyright 2025 深圳十米网络科技有限公司. All rights reserved.
    
    Use of this SDK is subject to the terms and conditions of the license agreement 
    between you and Your Company Name.
    
    Unauthorized copying of this file, via any medium is strictly prohibited.
    LICENSE
  }
  s.author           = { 'Anting Li' => 'anting.li@10.com.cn' }

  s.source           = { :http => 'https://github.com/novice-l/SMH5Game-Specs/releases/download/2.0.5/SMH5Game.xcframework.zip' }

  # s.resources = ['SMH5Game.xcframework/**/SMH5Game.bundle']

  s.ios.deployment_target = '12.0'

  s.vendored_frameworks = 'SMH5Game.xcframework'

  s.frameworks = [
    'AVFoundation',
    'CFNetwork',
    'CoreFoundation',
    'CoreGraphics',
    'CoreMedia',
    'CoreServices',
    'Foundation',
    'ImageIO',
    'QuartzCore',
    'Security',
    'UIKit',
    'WebKit'
  ]
  s.libraries = 'xml2', 'c++', 'z'

  # 第三方库依赖 (CocoaPods 会自动帮你下载并解决冲突)
  # s.dependency 'SSZipArchive' 
  
  # 如果你的 SDK 是 Swift 写的，需要指定
  # s.swift_version = '5.0'
  
  # 解决一些架构问题 (通常不需要，除非编译报错)
  # s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
end
