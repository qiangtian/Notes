//
//  Method_Class.m
//  TQSomething
//
//  Created by Jay on 16/1/8.
//  Copyright © 2016年 TQ. All rights reserved.
//

#import "Method_Class.h"

@implementation Method_Class

/*
 * 按钮的状态颜色
 */
- (UIImage *)imageWithColor:(UIColor *)color
{
    CGRect rect = CGRectMake(0.0f, 0.0f, 1.0f, 1.0f);
    UIGraphicsBeginImageContext(rect.size);
    CGContextRef context = UIGraphicsGetCurrentContext();
    
    CGContextSetFillColorWithColor(context, [color CGColor]);
    CGContextFillRect(context, rect);
    
    UIImage *image = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    return image;
}


// 将秒转换为指定格式的字符串
- (NSString *)strWithTimeInterval:(NSTimeInterval)interval
{
    int m = interval / 60;
    int s = (int)interval % 60;
    return [NSString stringWithFormat:@"%02d: %02d", m , s];
}

//将时间戳 转换为 时间
- (NSString*)getAtrueTime:(NSString*)numTime {
    
    NSTimeInterval timeThis=[numTime doubleValue];
    NSDate *detaildate=[NSDate dateWithTimeIntervalSince1970:timeThis];
    
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    
    [dateFormatter setDateFormat:@"yy-MM-dd HH:mm"];
    
    return [dateFormatter stringFromDate: detaildate];
}


//获取周几数
- (NSString *)weekDayofDate:(NSDate *)date
{
    NSCalendar *gregorian = [[NSCalendar alloc]
                             initWithCalendarIdentifier:NSGregorianCalendar];
    
    NSDateComponents *weekdayComponents =
    
    [gregorian components:(NSDayCalendarUnit | NSWeekdayCalendarUnit) fromDate:date];
    
    
    NSInteger weekday = [weekdayComponents weekday];
    NSString *weekStr;
    switch (weekday) {
        case 1:
            weekStr = @"周日";
            break;
        case 2:
            weekStr = @"周一";
            break;
        case 3:
            weekStr = @"周二";
            break;
        case 4:
            weekStr = @"周三";
            break;
        case 5:
            weekStr = @"周四";
            break;
        case 6:
            weekStr = @"周五";
            break;
        case 7:
            weekStr = @"周六";
            break;
        default:
            break;
    }
    return weekStr;
    
}

@end
