//
//  link.h
//  TQSomething
//
//  Created by Jay on 16/1/12.
//  Copyright © 2016年 TQ. All rights reserved.
//

#ifndef link_h
#define link_h


#endif /* link_h */



1.地图
{
    // http://www.cnblogs.com/kenshincui/p/4125570.html
    打开第三方地图
   // https://www.cnblogs.com/niit-soft-518/p/8866768.html
}
2.多媒体
{
    // http://www.cnblogs.com/kenshincui/p/4186022.html
}
3.蓝牙
{
    // http://liuyanwei.jumppo.com/2015/09/11/ios-BLE-4.html
    // http://liuyanwei.jumppo.com/2015/08/14/ios-BLE-2.html
}
4.推送
{
    // http://blog.csdn.net/shenjie12345678/article/details/41120637
}
5.一些小知识
{
    //http://www.jianshu.com/p/8c1904ac106e
}

{
    //block
    http://www.cnblogs.com/biosli/p/block_usage.html
}
6.面试
{
    //http://zhangmingwei.iteye.com/blog/1748431
    
    // http://blog.sunnyxx.com/2015/07/04/ios-interview/
    
    很多// http://www.henishuo.com/ios-interview-entrance/
    
    // https://github.com/MisterBooo/ReadyForBAT
}

7.GitHub上传
{
    // https://www.cnblogs.com/shenchanghui/p/7184101.html
   // http://blog.csdn.net/bolu1234/article/details/52419131
}

8.灌水动画
{
    // https://github.com/dsxNiubility/SXWaveAnimate
}

9.js快捷键
{
    // http://blog.csdn.net/eternal1d/article/details/77752319
}

10.轮播图
{
    //https://github.com/WenchaoD/FSPagerView
}

11.安装pods
{
    // https://www.jianshu.com/p/9e4e36ba8574
}

12.图标尺寸 官网
{
    // https://developer.apple.com/ios/human-interface-guidelines/icons-and-images/app-icon/
}

13.数据结构
{
    //    https://blog.csdn.net/qq_31196849/article/details/78529724
}

14.内存
{
    // http://yulingtianxia.com/blog/2015/12/06/The-Principle-of-Refenrence-Counting/
    // http://www.cocoachina.com/ios/20180309/22518.html
}

蓝牙开发 corebluetooth框架，蓝牙开发主要分为两种 peripheral/central,外设和中心，作为中心时：cbcentralmanager/cbperipheral/cbservice/cbcharacteristic/cbuuid/property

中心模式流程：1.建立中心角色：cbcenteralmanager
            centermanagerdidupdatestate
            2.扫描外设
                manager scanforperipheral
                diddiscoverperipheral
            3.连接外设
              manager connectperpheral
            4.扫描服务和特征
              perpheral discoverServices
              perpheral discovercharacteristics
            5.写入数据，注册通知
                perpheral setvalue:forcharacteristicstype
                perpheral setnotifyvalue yes forcharacteractics
des+base64
rc4
异或。数据为交换
NSdata *data = [nsdata alloc]initwithbase64encoding


coreanimation

cashapelayer 确定外置，设置线的属性，fillcolor,linecap
uibezierpath 线,画圆，bezierpaythwitharccenter radious startangle clockwise
shapelayer.path = uibezierpath
cabasicanimation,removedoncompletion,timingfunctionduration,fromvalue,tovalue strokeend

eventkit

ekeventstore  requestaccess
ekevent = ekevent eventwithstore
event addalarm ekalarm alarmwithrelating


13.内存 block
{
    https://www.jianshu.com/p/492be28d63c4
}








