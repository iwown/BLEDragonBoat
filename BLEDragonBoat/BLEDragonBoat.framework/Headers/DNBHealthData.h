//
//  DNBHealthData.h
//  BLE3Framework
//
//  Created by 曹凯 on 16/10/12.
//  Copyright © 2016年 ZR. All rights reserved.
//
#import <Foundation/Foundation.h>

typedef struct {
    uint16_t year;
    uint8_t month;
    uint8_t day;
}DNB_RecorDate;

typedef struct {
    DNB_RecorDate rcDate;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
}DNB_RecortDate;

typedef struct {
    uint16_t seqStart;
    uint16_t seqEnd;
    DNB_RecortDate storeDate;
}DNB_DateDataInfo;

typedef struct {
    uint8_t dataType;
    uint8_t totaldays;
    DNB_DateDataInfo ddInfos[7];
}DNB_TDateStoreInfo;

@interface DNBDDInfo : NSObject

+ (instancetype)objectFrom:(DNB_DateDataInfo)ddInfo;
@property (nonatomic ,strong) NSDate *date;
@property (nonatomic ,assign) NSInteger seqStart;
@property (nonatomic ,assign) NSInteger seqEnd;

@end


@interface DNBDataInfo : NSObject

@property (nonatomic ,strong) NSArray <DNBDDInfo *> *ddInfos;
@property (nonatomic ,assign) NSUInteger dataType;

- (NSArray <NSDate *>*)getDateArray;

@end


@interface DNBHealthData : NSObject
/**! Sequence number*/
@property (assign ,nonatomic) NSInteger seq;
/**! Specifical data type*/
@property (nonatomic ,assign) NSInteger sdType;
/**! Timestamp of data*/
@property (strong ,nonatomic) NSDate *recordDate;
/**! Device name*/
@property (class, copy ,nonatomic)NSString *dataFrom;

@end
