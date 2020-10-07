//
//  PACarDetectManager.h
//  PADetectAI
//
//  Created by 杨通(平安科技智能引擎部智能产品开发组) on 2019/5/22.
//  Copyright © 2019 杨通(平安科技智能引擎部智能产品开发组). All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PADetectModel.h"
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger,kDamageDetectState){
    kDamageDetectStateModelFailed,      //损伤模型加载失败
    kDamageDetectStateDamaged,          //有损伤
    kDamageDetectStateNormal            //无损伤
};

@interface PACarDetectManager : NSObject
/*
 Note：加载模型
 confidenceValue: 置信度，建议选择0.6 以上；
 */

- (instancetype)initWithConfidence:(float)confidenceValue;

/*
 Note：部位损伤判断
 image: 检测损伤模型
 返回类型：kDamageDetectState
 
 */
- (kDamageDetectState)detectDamageImage:(UIImage *)damageImage;

/*
 Note：加载部位模型
 参数：
    image: 检测损伤模型
 返回：
 NSMutableArray；
    遍历数组，获取PADetectModel；
 */
- (NSMutableArray *)detectCarPart:(UIImage *)image;
@end


NS_ASSUME_NONNULL_END
