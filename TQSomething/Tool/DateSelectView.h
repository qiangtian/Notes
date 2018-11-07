//
//  DateSelectView.h
//  TXLaoXiang
//
//  Created by Jay on 16/1/7.
//  Copyright © 2016年 WolfCub. All rights reserved.
//  时间选择器

#import <UIKit/UIKit.h>
//#import "ProjectSetting.h"

@protocol DateSelectViewDelegate <NSObject>

- (void)finishSelectDate:(NSString* )date;

@end

@interface DateSelectView : UIView

@property (nonatomic, strong) UIDatePicker* agePicker;
@property (nonatomic, strong) UIView*  backView;//选择时间背景
@property (nonatomic, strong) UILabel* ageLab;//显示时间label
@property (nonatomic, strong) NSDate* selectDate;//选择的时间


@property (nonatomic, assign) id <DateSelectViewDelegate> delegate;

-(id)initWithFrame:(CGRect)frame andType:(NSInteger)type ; //0 time 1 date

@end
