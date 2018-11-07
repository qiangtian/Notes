//
//  Interview.h
//  TQSomething
//
//  Created by 西安旺豆电子 on 2018/3/12.
//  Copyright © 2018年 TQ. All rights reserved.
//

#ifndef Interview_h
#define Interview_h


#endif /* Interview_h */


#pragma mark - 1. cell优化
{
    1.重用机制
    2.设定cell高度，self.tableView.rowHeight = 88;
    3.减少视图数目
    4.不动态加载视图
    5.异步加载图片，单个cell图片过多或者请求时间过长时，可以在tableview停止滑动之后加载，用scrollviewDidEndDragging和 scrollviewDidEndDecelerating获知停止滑动
    6.减少透明层，当设置为透明时，需要混合每一层的颜色计算得到最终的颜色。不透明时，只取最上面的层的颜色。
    7.阴影设置路径。iOS会先绘制阴影，然后绘制目标本身，这是要通过递归每个字层，计算阴影的路径。利用贝塞尔曲线画路径
}

#pragma mark - 2. delegate kvc 通知
{
    1.delegate:语法清晰，效率高
    将一件事情交给另一个被委托着处理

    一对一；代码较多
    @protocol testdelegate <nsobject>
    - (void)test;
    @end
    2.NSNotification:代码简单，一对多
    需要取消注册；太多的话难以维护
    [[nsnotification defaultcenter] addobserer:self selecton@() name:@"enevt1" object:nil];
    3.KVO:观察对象的属性，不是控制器之间的
    观察者必须用strings定义
    原理：当观察某对象A,kvo会动态创建一个该类的子类，并为这个子类重写被观察属性keypath的setter方法。setter方法之后会负责通知属性的改变情况。
    nskvonotifying_A新类
    
    
}

#pragma mark - 3.设计模式
{
    1.代理
    2.观察者   通知 和 kvo
    3.MVC    层次清晰，易于维护
    4.单例    某个类只有一份实例
    5.MVVM   mvc的增强版,mvc是view/model/vc，mvvm是model/view/viewmodel
    viewmodel中是view和model的逻辑业务层，vc中不再处理数据的逻辑获取，都是放到viewmodel中
}
#pragma mark - 4. 分类 扩展
{
    1.分类 category：不修改原类，扩展方法，不能添加成员变量
    @interface UIView (category)
    -(void)test;
    @end
    在不获悉、不改变原代码的情况下；
    只能添加方法，不能修改原类中方法，方法重名时，会覆盖原类方法
    
    2.扩展 extension：可以添加成员变量，特例分类；扩展中方法是一定要实现的
}

#pragma mark - 5. 动态语言
{
    静态类型语言：类型判断在运行前判断；优点：结构规范，便于调试，缺点：代码较多，不清晰
    动态类型语言：方便阅读；不方便调试
    
    // 体现
    oc在程序运行时才会去确定对象的类型，并调用类与对象相应的方法
    1.动态类型：id类型，在运行时才能决定是什么类型
    2.动态绑定：
    3.动态加载
}

#pragma mark - 6.RunTime
{
     // https://www.cnblogs.com/allencelee/p/7573627.html
    // http://yulingtianxia.com/blog/2014/11/05/objective-c-runtime/
    
    // tableview 优化
    // http://blog.sunnyxx.com/2015/05/17/cell-height-calculation/
    运行时，是主要的消息机制。基于c语言写的。
    
    //函数定义
    object_       对象操作方法
    class_      对类操作方法
    method_     对类或对象方法 操作的方法
    ivar_       对变量进行操作的方法
    property_   对属性进行操作的方法
    protocol_   对协议进行操作的方法
    
    objc_       可以获取内存中类的信息、属性、对象等
    
    1.//方法调用的本质就是 让对象发送消息
    objc_msgSend
    objc_msgSend(p,@selector(eat)); == [p eat];
    
    2.//关联对象
    给分类动态添加属性
    objc_getAssociatedObject
    objc_setAssociatedObject
    3.//交换方法
    场景：自己创建了一个功能性方法，被多次引用。当需求改变时，需要使用另一个功能代替这个方法。
    再写一个新方法，然后交换两个方法，就在只是新增代码而不改变代码的情况下，完成了方法替换。
    一般写在viewload里面。
    Method imageWithName = class_getclassMethod(self,@selector(imageWithName:));
    Method imageName = class_getclassMethod(self,@selector(imageNamed:));
    //交换
    method_exchangeImplementations(imageWithName,imageName);
    4.字典转模型
    objc_property_t *propertyList = class_copyPropertyList{[self class],&outcount};
    
}

#pragma mark - 7.定时器
{
    1.NSTherd
    //创建一个后台线程执行计时操作
    self performSelectorInBackground
    //主线程更新ui
    self performSelectorOnMainThread
    
    2.NSTimer
    self.timer = [NSTimer scheduleTimerWithTimerInterval:1.0 target:self selector:@selector(handleTimer) userInfo:nil repeats:YES];
    [self.timer invalidate];
    
    3.GCD
    dispatch_queue_t queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT,0);
    dispatch_source_t timer = dispatch_source_create(DISPATCH_SOURCE_TYPE_TIMER,0,0,queue);
    dispatch_source_set_timer(timer,DISPATCH_TYPE_NOW,1*NESC_PER_SEC,0*NSEC_PER_SEC);
    dispatch_source_set_event_handler(timer,^{
        
        
        }
    })
}

#pragma mark - 8.GCD

{
    1.概念
    线程：程序执行任务的最小单位
    任务：一段代码
    队列：存放任务的数组
    并行：同时执行
    串行：按顺序执行
    同步：不开新线程，任务必须执行完才能继续往下走
    异步：可以开新线程，任务可以先绕过，再执行
    
    2.队列
    队列：dispatch_quque_t queue = dispatch_queue_create()
    主队列：dispatch_queue_t queue = dispatch_get_main_queue()
    主队列是串行队列，所有任务放在主线程中执行
    全局队列：并发队列
    3.disptach_after延时调用
    
    4.dispatch_group
    在 两个任务结束之后 执行下一个任务。
    dispatch_queue_t queue = dicpatch_get_global_queue
    dispatch_group_t group = dispatch_group_creat()
    
    dispatch_group_async(group,queue,^{任务a});
    ...
    dispatch_group_notify(group,dispatch_get_main_queue(),{最后一个任务});
    
    5.dispatch_once
    保证在应用程序中只执行一次代码
}

#pragma mark - 9.CALayer - UIView
{
    1.概念
    创建uiview时，内部会创建layer层，layer负责绘图uiview；view的属性
    CALayer: 内容展示 动画操作，不影响事件
    
    区别联系：
        每个UIView 内部都有一个 CALayer 提供内容的绘制和显示，并且尺寸样式都由Layer决定。View 可以接受事件，Layer不可以。
    uiview继承自UIResponder类，而CALayer继承自NSObject;
    uiview的frame，由layer的frame决定；
    uiview是对显示内容的管理，calayer显示内容的绘制；
}

#pragma mark - 10.NSURLSession
{
    
    
}


#pragma mark - 11. http格式
{   // https://www.jianshu.com/p/0dd08712c649
    // https://www.jianshu.com/p/6e9e4156ece3
    1.http协议：超文本传输协议
        请求格式：
            请求头 -- 环境描述，请求信息等
            GET   -- 请求方法、资源路径、http协议版本
            Host  -- 服务器主机地址
            User-Agent -- 客户端类型，软件环境
            Accept:text/html -- 客户端接受数据类型
            Accept-Language:zh-cn -- 客户端语言环境
            Accept-Encoding:gzip -- 客户端支持的数据压缩格式
            请求体：发送给服务器的具体数据
        响应格式：
            响应头： -- 对服务器描述、对返回数据的描述
            HTTP/1.1 -- http协议版本、状态码
            Server:Apache-Coyote -- 服务器类型
            Content-Type:image/jpeg -- 返回数据类型
            Content-Length:56811 -- 返回数据长度
            Date:Mon -- 响应时间
    
    2.RUL
        URL 基本格式：= 协议://主机地址/路径
    
        GET:
            在请求url 后面 以 ？形式拼接发送给服务器的参，多个参数之间用&隔开
        POST:
            发送给服务器的参数全部放在请求体中
    
    3. 断点续传
            range：请求的资源范围 bytes=306302- ：请求这个资源从306302个字节到末尾的部分；
            Content-Range: bytes 306302-604047/604048：响应中指示携带的是该资源的第306302-604047的字节，该资源共604048个字节；
        多线程下载：开启多个发出HTTP请求的线程，每个http请求只请求资源文件的一部分，例如：Content-Range: bytes 20000-40000/47000；
    
    4.https
        认证过程：1，客户端输入网址链接服务端；
                2，服务器返回证书（包含公钥、证书信息等），证书由服务器私钥非堆成加密生成；
                3，客户端 验证证书；
                4，验证通过，客户端生成一个 ‘随机数‘，用服务器返回的公钥加密；
                5，服务器用私钥解密，拿到‘随机数’，对数据用‘随机数’加密；
                6，客户端用‘随机数’解密。

}



#pragma mark - 53. 第三方原理
{
    1.IQKeyboardManager
        // https://www.jianshu.com/p/664efa555f71
    
    1.重写了 +(void)load;
        load: 在被引入项目时，就会执行load函数，每个类load函数只会自动调用一次，系统自动加载。 父类load方法 优先子类，类优先于类别，多个类别时，与compile source顺序一致。
    2.使用__weak typeof(self) weakSelf = self; 防止循环引用
      使用__strong typeof(self) strongSelf = weakSelf; 防止多线程下，self会在过程中被析构。
    3.canclesTouchedInView. 默认yes, 执行actionclick事件。
        NO,会都执行。
    4. [self showLog:[NSString stringWithFormat:@"****** %@ started ******",NSStringFromSelector(_cmd)]];
    
    5. 递归找可滚动的父视图，没有就调整widow

}

    
// ************** AFNetWorking *****************
    // http://www.cnblogs.com/machao/p/5790708.html
    /**
     *  AFNetworkReachabilityManager
     */
    1.AFNetworkReachabilityManager  // 监听网络状态
        封装 SCNetworkReachability。
        主要转换flags方法使用c语言函数，内联函数
        通过networkReachabilityStatusBlock，block得到目前状态
    核心监听代码是 SCNetworkReachability 部分：// http://www.cnblogs.com/machao/p/5681645.html
    主要流程：a.建立上下文，SCNetworkReachabilityContext；
            b.设置回掉，SCNetworkReachabilitySetCallback(self.networkReachability, AFNetworkReachabilityCallback, &context);
            c.加入runloop；
            SCNetworkReachabilityScheduleWithRunLoop(self.networkReachability, CFRunLoopGetMain(), kCFRunLoopCommonModes);
    
    
    /**
     *  AFSecurityPolicy
     */
        验证证书是否正确。
    /**
     *  AFURLResponseSerialization
     */
        返回数据解析。
        主要通过遵守协议，对不同的类型数据 进行不同方法解析。
          json\xml\plist\image\compound
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

typedef void(^returnBlock)(NSString *text);
@protocol testdelegate
- (void)test;
@property (weak, nonatomic) id <testdelegate> delegate;


static Singleton *singleton = nil;
+ (Singleton *)defaultSingleton {
    @synchronized(self) {
        if (singleton == nil) {
            singleton = [[Singleton alloc] init];
        }
    }
    return singleton;
}

static Singleton *singleton = nil;
+ (Singleton *)shareSingleton {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        if (singleton == nil) {
            singleton = [[Singleton alloc]init];
        }
    });
    return singleton;
}


- (void)setAge:(nsinteger)age {
    _age = age;
}

- (NString *)str {
    if (_str = nil) {
        _str = [nsstrinf alloc init];
        
    }
    
    return _str;
}
sizethatFits 初始化时不设置rect大小，就不会调用drowrect方法
setneedsdisplay



{
    // 自定义pagecontrol图片
    UIPageControl *pageControl = [[UIPageControl alloc] init];
    [pageControl setValue:[UIImage imageNamed:@"home_slipt_nor"] forKeyPath:@"_pageImage"];
    [pageControl setValue:[UIImage imageNamed:@"home_slipt_pre"] forKeyPath:@"_currentPageImage"];
    
}










