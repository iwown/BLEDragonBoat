//
//  BLEAutumn.h
//  BLESolstice
//
//  Created by A$CE on 2017/10/9.
//  Copyright © 2017年 A$CE. All rights reserved.
//

#define BLE_MAIN_RESTORE_IDENTIFIER @"com.iwown.autumn"
#define BLE_MID_AUTUMN_PLIST @"midAutumn"  //Config file name in @"midAutumn.plist";

#import "BLESolstice.h"
#import "BLEQuinox.h"
#import <Foundation/Foundation.h>

/**
 Core class, management search and connection, is also the entrance to the SDK.
 Sample @code{self.bleautumn = [BLEAutumn midAutumn];
 self.bleautumn.discoverDelegate = self;
 self.bleautumn.connectDelegate = self;}@endcode
 */
@interface BLEAutumn : NSObject

@property (nonatomic ,weak) id<BleDiscoverDelegate>discoverDelegate;
@property (nonatomic ,weak) id<BleConnectDelegate>connectDelegate;

/**
 Represents the current state of a CBManager. <CBManagerState> <CBCentralManagerState> used for below iOS10.
 @return Return to the state of the central manager, you can determine the status of Bluetooth.
 */
- (NSInteger)readManagerPowerState;

/**
 * Get the peripheral state
 */
- (CBPeripheralState)getPeripheralState;

/**
 Scan device. You will get the discovered devices in the callback method of discoverDelegate @see solsticeDidDiscoverDeviceWithMAC:
 @param seconds Enter a number of seconds that you want to stop searching after later
 @param uuids The uuids you want to specify when searching
 @param options Same with options in @method scanForPeripheralsWithServices:options:
 */
- (void)startScanForTimeInternal:(NSTimeInterval)seconds
                 andServiceUuids:(NSArray <NSString *>*)uuids
                      andOptions:(NSDictionary<NSString *, id> *)options;
/**
 @see startScanForTimeInternal:andServiceUuids:andOptions:
 Default options is nil.
 @param seconds The uuids you want to specify when searching
 @param uuids Same with options in @method scanForPeripheralsWithServices:options:
 */
- (void)startScanForTimeInternal:(NSTimeInterval)seconds
                 andServiceUuids:(NSArray <NSString *>*)uuids;
/**
 @see startScanForTimeInternal:andServiceUuids:
 Default seconds is 10, uuids is nil, The SDK will choose the correct uuids for the  <BLEProtocol>.
 */
- (void)startScan;
/**
 Stop scan.
 The SDK calls the @see solsticeStopScan method if you have already implemented it.
 */
- (void)stopScan;

/**
 Bind and connect the device. What's the 'Band' is SDK will help you remember the uuid of this device, and reconnect it when you call the reConnectDevice method.
 @method solsticeDidConnectDevice: in <BleConnectDelegate>
 @param device The device you want to connected that had discovered
 */
- (void)bindDevice:(ZRBlePeripheral *)device;
/** Give up that bond*/
- (void)unbind;
/** Whether it is bound*/
- (BOOL)isBound;
/** That NSUuid.identifer that was remembered*/
- (NSString *)bindUuidStr;

/**
 Reconnect the bound device

 @return In most cases it is nil, unless you have not bound the device, you will get a "No binding device" prompt
 */
- (NSError *)reConnectDevice;
/** Cancel Connect*/
- (void)cancelConnect;

/*Class Method ,use @CODE{[[BLEAutumn alloc] init];} and @CODE{setBleProtocol:} is samed */
+ (instancetype)midAutumn;

/**
 * If you need a <BLESolstice> object to communicate with device, after searching and connecting to the device with BLEAutumn, please using the this method initinal the object, or you have a peripheral device that has been connected without BLEAutumn, you can use the @see solsticeWithConnectedPeripheral: method.

 @return Follow the BLESolstice protocol for communication between the Operations Center and its surroundings
 */
- (id<BLESolstice>)solstice;

/**
 @see solstice

 @param zrPeripheral the Device had connected
 @return Follow the BLESolstice agreement object
 */
- (id<BLESolstice>)solsticeWithConnectedPeripheral:(ZRBlePeripheral *)zrPeripheral;

/**
 Call this method after initinal <BLESolstice> object; or ,you can not got any data callback from SDK.
 
 @param equinox The object that implements the <BLEQuinox> protocol method, accepts data from sdk
 */
- (void)registerSolsticeEquinox:(id<BLEQuinox>)equinox;

@end
