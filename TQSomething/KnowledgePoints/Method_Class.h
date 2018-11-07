//
//  Method_Class.h
//  TQSomething
//
//  Created by Jay on 16/1/8.
//  Copyright © 2016年 TQ. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface Method_Class : NSObject

/*
 * 按钮的状态颜色
 */
- (UIImage *)imageWithColor:(UIColor *)color;

/*
 * 将秒转换为指定格式的字符串
 */
- (NSString *)strWithTimeInterval:(NSTimeInterval)interval;

//将时间戳 转换为 时间
- (NSString*)getAtrueTime:(NSString*)numTime;
@end
