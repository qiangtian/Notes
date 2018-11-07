//
//  DateSelectView.m
//  TXLaoXiang
//
//  Created by Jay on 16/1/7.
//  Copyright © 2016年 WolfCub. All rights reserved.
//

#import "DateSelectView.h"

@interface DateSelectView () {
    
    NSInteger currentType;//0 time 1 date
}

@end

@implementation DateSelectView


-(id)initWithFrame:(CGRect)frame andType:(NSInteger)type {
    
    self = [super initWithFrame:frame];
    
    if (self) {
        
        currentType = type;
        
        //[self setup];
        
    }
    
    return self;
}

//- (void)setup
//{
//    
//    CGFloat ageLabH = 60;
//    CGFloat whiteViewH = 280;
//    CGFloat agePickerH = 180;
//    //遮挡
//    _backView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, TX_SCREEN_WIDTH, TX_SCREEN_HEIGHT)];
//    _backView.backgroundColor = TX_RGBA(0, 0, 0, 0.2);
//    [self addSubview:_backView];
//    UITapGestureRecognizer* tapGesRecongizer = [[UITapGestureRecognizer alloc]initWithTarget:self action:@selector(tapBackView)];
//    [_backView addGestureRecognizer:tapGesRecongizer];
//    
//    
//    //白色背景
//    UIView* whiteBackView = [[UIView alloc]initWithFrame:CGRectMake(16, TX_SCREEN_WIDTH/2, TX_SCREEN_WIDTH - 32, whiteViewH)];
//    whiteBackView.backgroundColor = [UIColor whiteColor];
//    whiteBackView.layer.cornerRadius = 5;
//    whiteBackView.layer.masksToBounds = YES;
//    [_backView addSubview:whiteBackView];
//    
//    //显示年龄label
//    _ageLab = [[UILabel alloc]initWithFrame:CGRectMake(0, 0, TX_SCREEN_WIDTH-32, ageLabH)];
//    _ageLab.font = TX_FONT(20);
//    _ageLab.textColor = TX_RGB(14, 197, 96);
//    _ageLab.textAlignment = NSTextAlignmentCenter;
//    [whiteBackView addSubview:_ageLab];
//    //绿线
//    UILabel* line = [[UILabel alloc]initWithFrame:CGRectMake(0, 58, TX_SCREEN_WIDTH-32, 2)];
//    line.backgroundColor = TX_RGB(14, 197, 96);
//    [whiteBackView addSubview:line];
//    
//    //选择器
//    _agePicker = [[UIDatePicker alloc]initWithFrame:CGRectMake(0, ageLabH, TX_SCREEN_WIDTH - 32, agePickerH)];
//    _agePicker.backgroundColor = TX_RGB(245, 245, 245);
//    
//    //显示当前时间或者年龄，根据type设置 时间 或者日期
//    if (currentType == 1)
//    {
//        _agePicker.datePickerMode = UIDatePickerModeDate;
//        _ageLab.text = @"0岁";
//        _agePicker.maximumDate = [NSDate date];
//        NSDate* minDate = [NSDate dateWithTimeIntervalSince1970:70*3600*24*366];//最小时间设为1970年之前70年  岁
//        _agePicker.minimumDate = minDate;
//
//    }else
//    {
//        _agePicker.datePickerMode = UIDatePickerModeDateAndTime;
//        NSDateFormatter* dateFormatter = [[NSDateFormatter alloc]init];
//        [dateFormatter setDateFormat:@"yyyy-MM-DD HH:mm"];
//        NSDate* now = [NSDate date];
//        [_ageLab setText:[dateFormatter stringFromDate:now]];
//        _agePicker.minimumDate = [NSDate date];
//    }
//    
//    
//    //添加值改变事件，改变agelabel的显示
//    [_agePicker addTarget:self action:@selector(changeAgeLab) forControlEvents:UIControlEventValueChanged];
//    [whiteBackView addSubview:_agePicker];
//    
//    //按钮
//    UIButton* cancleBtn = [[UIButton alloc]initWithFrame:CGRectMake(0, agePickerH+ageLabH, whiteBackView.frame.size.width/2, 40)];
//    UIButton* sureBtn = [[UIButton alloc]initWithFrame:CGRectMake(whiteBackView.frame.size.width/2, agePickerH+ageLabH, whiteBackView.frame.size.width/2, 40)];
//    
//    [cancleBtn setTitle:@"取消" forState:UIControlStateNormal];
//    [cancleBtn setTitleColor:TX_RGB(102, 102, 102) forState:UIControlStateNormal];
//    cancleBtn.titleLabel.font = TX_FONT(18);
//    [cancleBtn addTarget:self action:@selector(tapBackView) forControlEvents:UIControlEventTouchUpInside];
//    [sureBtn addTarget:self action:@selector(finishSelectAge) forControlEvents:UIControlEventTouchUpInside];
//    [sureBtn setTitle:@"完成" forState:UIControlStateNormal];
//    sureBtn.titleLabel.font = TX_FONT(18);
//    [sureBtn setTitleColor:TX_RGB(14, 197, 96) forState:UIControlStateNormal];
//    [whiteBackView addSubview:cancleBtn];
//    [whiteBackView addSubview:sureBtn];
//    
//}

//计算年龄方法
- (NSInteger)ageWithDateOfBirth:(NSDate *)date;
{
    // 出生日期转换 年月日
    NSDateComponents *components1 = [[NSCalendar currentCalendar] components:NSDayCalendarUnit | NSMonthCalendarUnit | NSYearCalendarUnit fromDate:date];
    NSInteger brithDateYear  = [components1 year];
    NSInteger brithDateDay   = [components1 day];
    NSInteger brithDateMonth = [components1 month];
    
    // 获取系统当前 年月日
    NSDateComponents *components2 = [[NSCalendar currentCalendar] components:NSDayCalendarUnit | NSMonthCalendarUnit | NSYearCalendarUnit fromDate:[NSDate date]];
    NSInteger currentDateYear  = [components2 year];
    NSInteger currentDateDay   = [components2 day];
    NSInteger currentDateMonth = [components2 month];
    
    // 计算年龄
    NSInteger iAge = currentDateYear - brithDateYear - 1;
    if ((currentDateMonth > brithDateMonth) || (currentDateMonth == brithDateMonth && currentDateDay >= brithDateDay)) {
        iAge++;
    }
    
    return iAge;
}


- (void)changeAgeLab
{
    //获取当前选择的日期
    _selectDate = [_agePicker date];
    if (currentType == 1)
    {
        NSInteger age = [self ageWithDateOfBirth:_selectDate];
        NSString* selectAge = [NSString stringWithFormat:@"%ld岁", age];
        [_ageLab setText:selectAge];
    }else
    {
        NSDateFormatter* dateFormatter = [[NSDateFormatter alloc]init];
        [dateFormatter setDateFormat:@"yyyy-MM-DD HH:mm"];
        [_ageLab setText:[dateFormatter stringFromDate:_selectDate]];
    }
}
// 取消选择
- (void)tapBackView
{
    [self removeFromSuperview];
}
//完成
- (void)finishSelectAge
{
    NSString* returnText = [[NSString alloc]init];
    [self removeFromSuperview];
    if (currentType == 1)
    {
        NSInteger age = [self ageWithDateOfBirth:_selectDate];
        NSString* selectAge = [NSString stringWithFormat:@"%ld", age];
        returnText = selectAge;
    }else
    {
        NSDateFormatter* dateFormatter = [[NSDateFormatter alloc]init];
        [dateFormatter setDateFormat:@"yyyy-MM-DD HH:mm"];
        returnText = [dateFormatter stringFromDate:_selectDate];
    }

    if (self.delegate)
    {
        [self.delegate finishSelectDate:returnText];
    }
}


@end
