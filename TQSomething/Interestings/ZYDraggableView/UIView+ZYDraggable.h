//
//  UIView+ZYDraggable.h
//  DraggableView
//
//  Created by 张志延 on 16/8/25. (https://github.com/zzyspace)
//  Copyright © 2016年 tongbu. All rights reserved.
//  拖动view跟随手指移动，放开后回到原处  -- [view makeDraggable];

/**
 *  runtime:http://www.cnblogs.com/luoguoqiang1985/p/3551966.html 给扩展添加属性
 
 *  UIDynamic：http://www.cnblogs.com/lifengfneg/p/4774070.html 物理引擎
 */

#import <UIKit/UIKit.h>

@interface UIView (Draggable)

/**
 *  Make view draggable.
 *
 *  @param view    Animator reference view, usually is super view.
 *  @param damping Value from 0.0 to 1.0. 0.0 is the least oscillation. default is 0.4.
 */
- (void)makeDraggableInView:(UIView *)view damping:(CGFloat)damping;
- (void)makeDraggable;

/**
 *  Disable view draggable.
 */
- (void)removeDraggable;

@end
