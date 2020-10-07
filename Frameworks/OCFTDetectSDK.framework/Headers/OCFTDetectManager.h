//
//  OCFTDetectManager.h
//  OCFTDetectSDK
//
//  Created by 朱敏(保险支持团队保险研发组) on 2019/11/18.
//  Copyright © 2019 朱敏(保险支持团队保险研发组). All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, OCFTPartDetectTip){
    // 图片为空
    OCFTPartDetectImageNone = 1,
    // 请先鉴权
    OCFTPartDetectAuthenticationNone,
    // 请对准受损部位
    OCFTPartDetectNoPart,
    // 太靠左了，请稍微向右移动
    OCFTPartDetectLeft,
    // 太靠右了，请稍微向左移动
    OCFTPartDetectRight,
    // 太靠上了，请稍微向下移动
    OCFTPartDetectUp,
    // 太靠右了，请稍微向上移动
    OCFTPartDetectDown,
    // 距离过远，请稍微靠近
    OCFTPartDetectFar,
    // 图像过于模糊
    OCFTPartDetectFuzzy,
    // 聚焦到部位，并发现损伤，提醒拍照
    OCFTPartDetectNormal,
};

/* 部位检测结果
当tips提醒是OCFTDetectTipNormal时，partCode才会有值
*/
typedef void(^OCFTPartDetectBlock)(OCFTPartDetectTip partDetectTip, NSString *partCode);

@protocol OCFTDetectManagerDelegate <NSObject>
// 鉴权结果
- (void)onCheckPermissionMsgCode:(long)code msgString:(NSString *)message;
@end

@interface OCFTDetectManager : NSObject
// 单例
+ (instancetype)sharedInstance;

// 鉴权
- (void)checkPermisionWithCompanyID:(NSString *)companyID
                          publicKey:(NSString *)publicKey
                         privateKey:(NSString *)privateKey
                              debug:(BOOL)isDebug
                           delegate:(id <OCFTDetectManagerDelegate>)delegate;

// 检测图片 (在iPhoneX上实测部位检测耗时80~100ms，耗时略长于视频流返回的频率，所以需要以串行的方式传入image，上一张处理完再传入下一章图片，否则图片处理速度跟不上传入图片的速度，导致缓存区中的图片堆积过多，内存增长)
- (void)partDetect:(UIImage *)image completion:(OCFTPartDetectBlock)partDetectBlock;

// 获取SDK版本号
- (NSString *)getVersion;
@end

NS_ASSUME_NONNULL_END
