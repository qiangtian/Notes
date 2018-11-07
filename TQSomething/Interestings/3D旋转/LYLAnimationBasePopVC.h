//
//  LYLAnimationBasePopVC.h
//  TaoBao
//
//  Created by Rainy on 16/10/12.
//  Copyright © 2016年 Rainy. All rights reserved.

//  CATransform3D http://www.jianshu.com/p/44080eec7a1c
//  code4 项目：https://github.com/LiuYulei001/TaoBaoPayNowAnimation

#import <UIKit/UIKit.h>

@interface LYLAnimationBasePopVC : UIViewController

@property(nonatomic,strong) UIView * popView;

@property(nonatomic,strong) UIView * rootview;

@property(nonatomic,strong) UIViewController * rootVC;

@property(nonatomic,strong) UIView * maskView;

- (void)createPopVCWithRootVC:(UIViewController *)rootVC andPopView:(UIView *)popView;

@end
