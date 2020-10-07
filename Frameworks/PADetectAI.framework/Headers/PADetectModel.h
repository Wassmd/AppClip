//
//  PADetectModel.h
//  PADetectAI
//
//  Created by 杨通(平安科技智能引擎部智能产品开发组) on 2019/5/22.
//  Copyright © 2019 杨通(平安科技智能引擎部智能产品开发组). All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

NS_ASSUME_NONNULL_BEGIN

@interface PADetectModel : NSObject
@property (nonatomic,copy) NSString *className;     // 识别部位
@property (nonatomic, assign) float score;          // 置信度
@property (nonatomic, assign) CGRect cropImageRect; // 截取的图片坐标
@property (nonatomic,copy) NSString *classLabel;    // 部位编码
@end

NS_ASSUME_NONNULL_END
