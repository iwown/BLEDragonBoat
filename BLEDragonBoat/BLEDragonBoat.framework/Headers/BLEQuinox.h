//
//  BLEQuinox.h
//  BLEMidAutumn
//
//  Created by A$CE on 2018/9/10.
//  Copyright © 2018年 A$CE. All rights reserved.
//

#import <Foundation/Foundation.h>
@class ZRBlePeripheral;
/**
 DicoverDeleagte，Response delegate methods in discover device.
 */
@protocol BleDiscoverDelegate <NSObject>

@required

/**
 * This method is invoked while scanning
 
 @param iwDevice Instance contain a CBPeripheral object and the device's MAC address
 */
- (void)solsticeDidDiscoverDeviceWithMAC:(ZRBlePeripheral *)iwDevice;

/**
 * Search stopped
 */
- (void)solsticeStopScan;

@end

/**
 ConnectDeleagte，Response delegate methods in device connect method.
 */
@protocol BleConnectDelegate <NSObject>

@required
/**
 *  invoked when the device did connected by the centeral
 *
 *  @param device the device did connected
 */
- (void)solsticeDidConnectDevice:(ZRBlePeripheral *)device;

@optional

/**
 Invoked when the device did disConnect with the connectted centeral
 
 @param device The device whom the centeral was connected
 @param error In most cases it is nil
 */
- (void)solsticeDidDisConnectWithDevice:(ZRBlePeripheral *)device andError:(NSError *)error;
/**
 Invoked when the device did fail to connected by the centeral
 
 @param device The device whom the centeral want to be connected
 @param error In most cases it is nil
 */
- (void)solsticeDidFailToConnectDevice:(ZRBlePeripheral *)device andError:(NSError *)error;

/**! Bluetooth state changed off.<##>*/
- (void)centralManagerStatePoweredOff;
/**! Bluetooth state changed on.<##>*/
- (void)centralManagerStatePoweredOn;

@end


@class ZRDeviceInfo;
@class ZRDataInfo;
@class ZRHealthData;
@protocol BLEQuinox <NSObject>

@required
/**! The handshake is completed, the initial setup is completed, and the App business logic can be executed.<##>*/
- (void)bleSolsticeIsReady;
/**! Update the device information callback, which is called when the device's Bluetooth address, model number, version information, or battery status changes.*/
- (void)bleSolsticeUpdateDeviceInfo:(ZRDeviceInfo *)deviceInfo;

@optional
/**Return data information*/
- (void)updateNormalHealthDataInfo:(ZRDataInfo *)zrDInfo;
/**Return data.@See more in ZRHealthData*/
- (void)updateNormalHealthData:(ZRHealthData *)zrhData;
/**! Data synchronization progress, progress of a call to detailed data*/
- (void)responseDataProgress:(NSInteger)progress;
@end
