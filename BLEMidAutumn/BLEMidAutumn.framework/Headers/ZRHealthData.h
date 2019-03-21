//
//  ZRHealthData.h
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
}RecorDate;

typedef struct {
    RecorDate rcDate;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
}RecortDate;

typedef struct {
    uint16_t seqStart;
    uint16_t seqEnd;
    RecortDate storeDate;
}DateDataInfo;

typedef struct {
    uint8_t dataType;
    uint8_t totaldays;
    DateDataInfo ddInfos[7];
}TDateStoreInfo;

@interface DDInfo : NSObject

+ (instancetype)objectFrom:(DateDataInfo)ddInfo;
@property (nonatomic ,strong) NSDate *date;
@property (nonatomic ,assign) NSInteger seqStart;
@property (nonatomic ,assign) NSInteger seqEnd;

@end


@interface ZRDataInfo : NSObject

@property (nonatomic ,strong) NSArray <DDInfo *> *ddInfos;
@property (nonatomic ,assign) NSUInteger dataType;

- (NSArray <NSDate *>*)getDateArray;

@end


@interface ZRHealthData : NSObject
/**! Sequence number*/
@property (assign ,nonatomic) NSInteger seq;
/**! Specifical data type*/
@property (nonatomic ,assign) NSInteger sdType;
/**! Timestamp of data*/
@property (strong ,nonatomic) NSDate *recordDate;
/**! Device name*/
@property (class, copy ,nonatomic)NSString *dataFrom;

@end
