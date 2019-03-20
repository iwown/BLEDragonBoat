Pod::Spec.new do |s|

s.name         = 'BLEMidAutumn'

s.version      = "0.1.1"

s.summary      = 'BLE connect handle as a central manager'

s.license      = 'MIT'

s.author       = { "xuezou" => "377949550@qq.com" }

s.homepage     = 'https://github.com/xuezou/BLEMidAutumn'

s.source       = { :git => "https://github.com/xuezou/BLEMidAutumn.git", :tag => s.version}

s.platform     = :ios

s.ios.deployment_target = "9.0"

s.frameworks = 'Foundation'

s.vendored_frameworks = 'BLEMidAutumn/BLEMidAutumn.framework'

s.requires_arc = true

end
