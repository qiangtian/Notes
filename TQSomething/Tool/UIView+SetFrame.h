//
//  UIView+SetFrame.h
//  新浪微博--1008
//
//  Created by tingxunmac-1 on 15/10/9.
//  Copyright (c) 2015年 Tincent. All rights reserved.
//

#import <UIKit/UIKit.h>



/**
 *  构建view的size属性
 */
@interface UIView (SetFrame)

@property (nonatomic, assign) CGFloat x;
@property (nonatomic, assign) CGFloat y;

@property (nonatomic, assign) CGFloat centerX;
@property (nonatomic, assign) CGFloat centerY;
@property (nonatomic, assign) CGFloat width;
@property (nonatomic, assign) CGFloat height;
@property (nonatomic, assign) CGSize size;
@property (nonatomic, assign) CGPoint origin;

/**
 *  CGAffineTransformMakeScale
 */
@property (nonatomic) CGFloat  scale;

/**
 *  CGAffineTransformMakeRotation
 */
@property (nonatomic) CGFloat  angle;
@end
