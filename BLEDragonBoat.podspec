Pod::Spec.new do |s|

s.name         = 'BLEDragonBoat'

s.version      = "0.5.0"

s.summary      = 'BLE connect handle as a central manager'

s.license      = 'MIT'

s.author       = { "xuezou" => "377949550@qq.com" }

s.homepage     = 'https://github.com/xuezou/BLEDragonBoat'

s.source       = { :git => "https://github.com/xuezou/BLEDragonBoat.git", :tag => s.version}

s.platform     = :ios

s.ios.deployment_target = "9.0"

s.frameworks = 'Foundation'

s.vendored_frameworks = 'BLEDragonBoat/BLEDragonBoat.framework'

s.requires_arc = true

end
