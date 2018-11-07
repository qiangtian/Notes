//
//  points.h
//  TQSomething
//
//  Created by Jay on 16/1/8.
//  Copyright © 2016年 TQ. All rights reserved.
//

#ifndef points_h
#define points_h


#endif /* points_h */
// http://www.cocoachina.com/ios/20160414/15918.html
//http://www.techug.com/ios-bat-interview
#pragma mark -  1.Block

Ivar
{
    1. 定义
    {
        返回值类型(^block变量名)(形参列表) = ^(形参列表){
            
        };
        调用Block保存的代码
        block变量名(实参);
    }
    
    typedef void (^RetturnTextBlock)(NSString* nameText);
    @property (nonatomic, strong) RetturnTextBlock returnTextBlock;
    - (void)returnText:(RetturnTextBlock)block;
    - (void)returnText:(RetturnTextBlock)block
    {
        self.returnTextBlock = block;
    }
    //
    [editNameViewController returnText:^(NSString *nameText) {
        self.nameText = nameText;
        [self.myTableView reloadData];
    }];
    
    //用系统的block
    @property (nonatomic, strong) dispatch_block_t reloadTableBlock;
    if (self.reloadTableBlock)
    {
        self.reloadTableBlock();
    }
    //
    admittanceDetailsViewController.reloadTableBlock = ^(){
        [self.myTableView headerBeginRefreshing];
    };
    
    //要想在块内改变x的值，需要使用__block修饰x
    
    // block注意的问题
    {
       // http://blog.sina.com.cn/s/blog_6cffce7701018fqj.html
        1、block中引用外部变量  解决：添加 __block _block int number = 1;
        2、block自身的内存管理
            block在创建的时候，它的内存是分配在栈(stack)上，而不是在堆(heap)上。他本身的作于域是属于创建时候的作用域，一旦在创建时候的作用域外面调用block将导致程序崩溃
        
            解决： _block = [_blockcopy];定义完block之后设置
        
        3、循环引用
            _block = ^(){
                NSLog(@"string %@", _string);
            };    // 这里的_string相当于是self->_string
        解决: __block ViewController *controller = self;
        
    }
}

#pragma mark - 2.代理
{
    @protocol TXAnnexCellDelegate
    
    - (void)changeCellHeight:(NSInteger)indexPath;
    @end
    @property (weak, nonatomic)id <TXAnnexCellDelegate> delegate;
    //weak和assign是一种“非拥有关系”的指针，通过这两种修饰符修饰的指针变量，都不会改变被引用对象的引用计数。但是在一个对象被释放后，weak会自动将指针指向nil，而assign则不会。
    if (self.delegate)
    {
        [self.delegate changeCellHeight:self.tag];
    }
}

#pragma mark - 3. Xcode添加常用代码片段
{
    http://blog.csdn.net/pingchangtan367/article/details/30041285
    http://www.2cto.com/kf/201403/289322.html
    /*
     * <#备注#>
     */
    

    //-设置状态栏的样式
    -(UIStatusBarStyle)preferredStatusBarStyle
    {
        //设置为白色
        //return UIStatusBarStyleLightContent;
        //默认为黑色
        return UIStatusBarStyleDefault;
    }
    // -设置状态栏是否隐藏（否）
    -(BOOL)prefersStatusBarHidden
    {
        return NO;
}

#pragma mark - 4.tableview设置线条   UIScrollView
{
    //没有横线
    self.myTableView.separatorStyle = UITableViewCellSeparatorStyleNone;
    //没有按下效果
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    //cell没有选中效果
    self.selectionStyle = UITableViewCellSelectionStyleNone;
    
    
    // UIScrollView
    frame 是可是范围大小
    contentsize  滚动范围
    contentoffset  滚动位置
    contentInset   4周额外的滚动区域
    
    //(2)使用构造方法
    //imageview
    UIImage *image=[UIImage imageNamed:@"minion"];
    _imageview=[[UIImageView alloc]initWithImage:image];
    //调用initWithImage:方法，它创建出来的imageview的宽高和图片的宽高一样
    
    
    3.//空值scrollview实现缩放图片
    scrollView.maximumZoomScale = 2.0;
    scrollView.minimumZoomScale = 0.5;
    - (UIView *)viewForZoomingInScrollView:(UIScrollView *)scrollView
    {
        return imageview;
    }
}


#pragma mark - 5.选择照片

{
    - (void)photo
    {
        UIImagePickerController *picker = [[UIImagePickerController alloc] init];
        picker.allowsEditing=YES;
        picker.delegate = (id)self;
        
        if (index == 2) {
            
            //拍照
            UIImagePickerControllerSourceType sourceType = UIImagePickerControllerSourceTypeCamera;
            if (![UIImagePickerController isSourceTypeAvailable: UIImagePickerControllerSourceTypeCamera]) {
                sourceType = UIImagePickerControllerSourceTypePhotoLibrary;
            }
            picker.sourceType = sourceType;
            [picker setVideoQuality:UIImagePickerControllerQualityTypeMedium];
            //        [self presentModalViewController:picker animated:YES];
            [self presentViewController:picker animated:YES completion:nil];
            
        }else if (index == 1) {
            
            //相册
            [picker setVideoQuality:UIImagePickerControllerQualityTypeMedium];
            [self presentViewController:picker animated:YES completion:nil];
        }
        
    }
    //选择
    - (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingImage:(UIImage *)image editingInfo:(NSDictionary *)editingInfo{
        
        [picker dismissViewControllerAnimated:YES completion:nil];
        
    }
    //取消
    - (void)imagePickerControllerDidCancel:(UIImagePickerController *)picker
    {
        [picker dismissViewControllerAnimated:YES completion:nil];
    }
}


#pragma mark - 6.设置按钮、label等  

{
    //设置圆角
    label.layer.cornerRadius = 5;
    label.layer.masksToBounds = YES;
    //设置圆角2
    //扩展方法
    
    /**
     * 图片设置填充
     */
    {
        imageView.autoresizingMask =  UIViewAutoresizingFlexibleLeftMargin | UIViewAutoresizingFlexibleRightMargin | UIViewAutoresizingFlexibleTopMargin | UIViewAutoresizingFlexibleBottomMargin;
        [imageView setContentMode:UIViewContentModeScaleAspectFill];

    }
    
 [text boundingRectWithSize:maxSize options:(NSStringDrawingUsesLineFragmentOrigin)
attributes:@{NSFontAttributeName:font} context:nil].size : CGSizeZero;

    
    
#import <UIKit/UIKit.h>
    
    @interface UIImage (Extension)

- (UIImage *)circleImage;

@end
#import "UIImage+Extension.h"
    
    @implementation UIImage (Extension)

- (UIImage *)circleImage {
    
    // 开始图形上下文
    UIGraphicsBeginImageContextWithOptions(self.size, NO, 0.0);
    
    // 获得图形上下文
    CGContextRef ctx = UIGraphicsGetCurrentContext();
    
    // 设置一个范围
    CGRect rect = CGRectMake(0, 0, self.size.width, self.size.height);
    
    // 根据一个rect创建一个椭圆
    CGContextAddEllipseInRect(ctx, rect);
    
    // 裁剪
    CGContextClip(ctx);
    
    // 将原照片画到图形上下文
    [self drawInRect:rect];
    
    // 从上下文上获取剪裁后的照片
    UIImage *newImage = UIGraphicsGetImageFromCurrentImageContext();
    
    // 关闭上下文
    UIGraphicsEndImageContext();
    
    return newImage;
}
具体使用:

// 获得的就是一个圆形的图片
UIImage *placeHolder = [[UIImage imageNamed:@"defaultUserIcon"] circleImage];



    //合并两张图片
    {
        //合并两张图片
        UIGraphicsBeginImageContextWithOptions(CGSizeMake(200, 100), NO, 0.0);
        [image1 drawInRect:CGRectMake(0, 0, 100, 100)];
        [image2 drawInRect:CGRectMake(100, 0, 100, 100)];
        self.imageView3.image=UIGraphicsGetImageFromCurrentImageContext();
        //关闭上下文
        UIGraphicsEndImageContext();
    }

}

#pragma mark - 7.富文本

{
    http://www.2cto.com/kf/201409/334308.html
    
    //后6个字符设置颜色
    NSMutableAttributedString *agreeText = [[NSMutableAttributedString alloc]initWithString:@"提交审核,即表示同意《合成协议》"];
    [agreeText addAttribute:NSForegroundColorAttributeName value:LX_BASE_COLOER range:NSMakeRange(agreeText.length - 6, 6)];
    //整体label添加方法
    UITapGestureRecognizer *tapAgree = [[UITapGestureRecognizer alloc]initWithTarget:self action:@selector(gotoSeeAgreeDetail)];
    [btnLab addGestureRecognizer:tapAgree];
    
    //方式一
    //创建 NSMutableAttributedString
    NSMutableAttributedString *attributedStr01 = [[NSMutableAttributedString alloc] initWithString: originStr];
    //添加属性
    //给所有字符设置字体为Zapfino，字体高度为15像素
    [attributedStr01 addAttribute: NSFontAttributeName value: [UIFont fontWithName: @"Zapfino" size: 15]
                            range: NSMakeRange(0, originStr.length)];
    
    //方式二
    //创建属性字典
    NSDictionary *attrDict = @{ NSFontAttributeName: [UIFont fontWithName: @"Zapfino" size: 15],
                                NSForegroundColorAttributeName: [UIColor blueColor] };
    //创建 NSAttributedString 并赋值
    _label02.attributedText = [[NSAttributedString alloc] initWithString: originStr attributes: attrDict];
    
    
    NSFontAttributeName                设置字体
    NSForegroundColorAttributeNam      设置字体颜色
    NSKernAttributeName                设定字符间距
    NSStrikethroughStyleAttributeName  设置删除线，取值为 NSNumber 对象（整数）
    NSStrikethroughColorAttributeName  设置删除线颜色，取值为 UIColor 对象，默认值为黑色
    NSUnderlineStyleAttributeName      设置下划线，取值为 NSNumber 对象（整数），枚举常量 NSUnderlineStyle中的值，与删除线类似
    NSUnderlineColorAttributeName      设置下划线颜色，取值为 UIColor 对象，默认值为黑色
    NSLinkAttributeName                设置链接属性，点击后调用浏览器打开指定URL地址
    NSObliquenessAttributeName         设置字形倾斜度，取值为 NSNumber （float）,正值右倾，负值左倾

    NSParagraphStyleAttributeName      //行间距
    NSMutableParagraphStyle* paragraph = [[NSMutableParagraphStyle alloc] init];
    paragraph.lineSpacing = 10;

}

#pragma mark - 8.添加手势方法

{
    //http://www.cnblogs.com/chglog/p/4696722.html
    
    //只有继承了UIResponder的对象才能接收并处理事件。我们称之为“响应者对象”
    
    //UIView的触摸事件处理
    - (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
    - (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event
    //UITouch
    - (CGPoint)locationInView:(UIView *)view; // 返回值表示触摸在view上的位置
    //UIEvent
    //手势识别
    UITapGestureRecognizer(敲击)
    UIPinchGestureRecognizer(捏合，用于缩放)
    UIPanGestureRecognizer(拖拽)
    UISwipeGestureRecognizer(轻扫)
    UIRotationGestureRecognizer(旋转)
    UILongPressGestureRecognizer(长按)
    
    UITapGestureRecognizer *tapAgree = [[UITapGestureRecognizer alloc]initWithTarget:self action:@selector(gotoSeeAgreeDetail)];
    [btnLab addGestureRecognizer:tapAgree];
    
}

#pragma mark - 9.电话、邮件、短信

{
    UIApplication *app = [UIApplication sharedApplication];
    //mailto://
    //sms://
    // NSString *num = [[NSString alloc] initWithFormat:@"tel://%@",number]; //number为号码字符串 如果使用这个方法 结束电话之后会进入联系人列表
    
    NSString *num = [[NSString alloc] initWithFormat:@"telprompt://%@",phoneNum]; //而这个方法则打电话前先弹框  是否打电话 然后打完电话之后回到程序中 网上说这个方法可能不合法 无法通过审核
    NSURL *url = [NSURL URLWithString:strUrl];
    [app openURL:url];
    
    //使用MessageUI框架发短信
    MFMessageComposeViewController *sms = [[MFMessageComposeViewController alloc]init];
    sms.recipients = @[@"10086",@"158"];
    sms.subject = @"test";
    sms.body = @"test";
    [self presentViewController:sms animated:YES completion:nil];
    sms.messageComposeDelegate = self;
    //回掉函数
    - (void)messageComposeViewController:(MFMessageComposeViewController *)controller didFinishWithResult:(MessageComposeResult)result

}

#pragma mark - 10.动画
{
    //慕课网
    //直接动画
    [UIView animateWithDuration:1.0 animations:^{
    }];
    //延时动画
    [UIView animateWithDuration:1.0 delay:0.5 options:UIViewAnimationOptionTransitionCrossDissolve animations:^{
    } completion:nil];
    
    options 的意思：// http://www.daxueit.com/article/5609.html
            以上方法中的options一项需要传入一个枚举，这个枚举大概控制的是这几个要素：当前动画嵌套中的动画执行随时间的快慢种类（先快后慢等..）。动画要一直重复吗。如果我使用转场动画那么我用哪种转场效果。还有子动画嵌套在父动画中时我们如何对待父动画中的相同选项等等..

    透明度：alpha
    缩放： lab5.transform = CGAffineTransformMakeScale(2.0, 2.0);//两倍
    颜色： label设置颜色渐变无效(dont k why)
    旋转： 递归 或者用timer 设置隔多少时间之后再执行一次
        [UIView animateWithDuration:1.0 delay:0.0 options:UIViewAnimationOptionCurveLinear animations:^{
            imageView.transform = CGAffineTransformRotate(imageView.transform, M_PI);
            self.imageView.transform = CGAffineTransformRotate(self.imageView.transform, M_PI_4);//旋转
             self.imageView.transform = CGAffineTransformScale(self.imageView.transform, 0.9, 0.9);//缩放
            _imageView.transform = CGAffineTransformTranslate(self.imageView.transform, 0, 10);
            //平移
        } completion:^(BOOL finished) {
            [self transform];
        }];


    //减速加速动画
    ease动画：easings.net
    options:
            UIViewAnimationOptionCurveEaseIn
            UIViewAnimationOptionCurveEaseOut
            UIViewAnimationOptionCurveEaseInOut
    //弹簧
    [UIView animateWithDuration:5 delay:0 usingSpringWithDamping:0.2 initialSpringVelocity:0 options:nil animations:^{
        [view5 setFrame:CGRectMake(120, self.view.frame.size.height - 100, 80, 80)];
    } completion:nil];
    usingSpringWithDamping：阻尼，即阻力
    initialSpringVelocity:初始速度
    
}

#pragma mark - 11.打开pdf等
{
    //QLPreviewController,在中化项目中用到过
    - (NSInteger)numberOfPreviewItemsInPreviewController:(QLPreviewController *)controller
    {
        return 1;
    }
    - (id<QLPreviewItem>)previewController:(QLPreviewController *)controller previewItemAtIndex:(NSInteger)index
    {
        VDZRCert* cert = self.CertDataArray[currentIndexPath];
        NSString* string = [[DownloadService shareInstance] downloadCachedDir];
        return [NSURL fileURLWithPath:[NSString stringWithFormat:@"%@/%@",string,cert.Z_FILENAME]];
    }

}

#pragma mark - 12.多媒体
{
    
    http://www.cnblogs.com/kenshincui/p/4186022.html
    1.音效---指的是一些短音频播放，通常作为点缀音频  SystemSoundID
   // #import <AVFoundation/AVFoundation.h>
    // -1.创建URL
    NSURL *url = [[NSBundle mainBundle] URLForResource:filename withExtension:nil];
    
    // 0.创建音效ID
    SystemSoundID soundID;
    AudioServicesCreateSystemSoundID((__bridge CFURLRef)(url), &soundID);
    
    // 1.播放音效(本地音效)
#warning ios8的模拟器不支持播放音效(真机可以)
    AudioServicesPlaySystemSound(soundID);
    
    // 2.销毁音效ID，不用的时候，内存紧张的时候
    AudioServicesDisposeSystemSoundID(soundID);

    2.音乐--AVAudioPlayer

    AVAudioPlayer不支持加载网络媒体流，只能播放本地文件
    duration 时长； volume 音量；currentTime 当前时长
    rate 播放速率；播放速率，范围0.5-2.0，如果为1.0则正常播放，如果要修改播放速率则必须设置enableRate为YES
     numberOfLoops：循环播放次数，如果为0则不循环，如果小于0则无限循环，大于0则表示循环次数
    
    - (BOOL)prepareToPlay; //加载音频文件到缓冲区
    - (BOOL)play;
    - (void)pause;
    - (void)stop;
    //设置进度条
    float progress= self.audioPlayer.currentTime /self.audioPlayer.duration;
    [self.playProgress setProgress:progress animated:true];
    
    3.MPMusicPlayerController用于播放音乐库中的音乐
    4.MediaPlayer.framework   视频播放   MPMoviePlayerController
    // http://blog.sina.com.cn/s/blog_6ec3c9ce01015byq.html
}

#pragma mark - 13.系统回自动设置布局
{
    //这个属性设置成no可以手动布局控制器自带的tableview
    //属性 会默认自动设置scrollview的contentInset;当内部有导航栏或者tabbar的时候 就会设置
    self.automaticallyAdjustsScrollViewInsets = NO;

}

#pragma mark - 14.正则表达式
{
    /d  数字
    .   任意字符
    ^   匹配输入字符串的开始位置
    $   匹配输入字符串的结束位置
    ? : 0个或者1个
    + : 至少1个
    * : 0个或者多个
    [] 包含,默认是一个字符长度
    [^] 不包含,默认是一个字符长度
    {n,m} 匹配长度
    |    或
    \    转义
    
    //使用系统NSRegularExpression
    NSString *atPattern = @"@[0-9a-zA-Z\\u4e00-\\u9fa5]+";
    NSString *topicPattern = @"#[0-9a-zA-Z\\u4e00-\\u9fa5]+#";
    NSRegularExpression *regex = [[NSRegularExpression alloc] initWithPattern:pattern options:0 error:nil];
    // | 匹配多个条件,相当于or\或
    NSString *pattern = [NSString stringWithFormat:@"%@|%@", atPattern, topicPattern];
    // 2.测试字符串
    NSArray *results = [regex matchesInString:str options:0 range:NSMakeRange(0, str.length)];
    // 3.遍历结果
    for (NSTextCheckingResult *result in results) {
        NSLog(@"%@ %@", NSStringFromRange(result.range), [str substringWithRange:result.range]);
    }
    
    //使用第三方库
    RegexKitLite
    // 遍历所有的匹配结果
    [str enumerateStringsMatchedByRegex:pattern usingBlock:^(NSInteger captureCount, NSString *const __unsafe_unretained *capturedStrings, const NSRange *capturedRanges, volatile BOOL *const stop) {
        NSLog(@"%@ %@", *capturedStrings, NSStringFromRange(*capturedRanges));
    }];

    // 以正则表达式为分隔符
    [str enumerateStringsSeparatedByRegex:pattern usingBlock:^(NSInteger captureCount, NSString *const __unsafe_unretained *capturedStrings, const NSRange *capturedRanges, volatile BOOL *const stop) {
        NSLog(@"%@ %@", *capturedStrings, NSStringFromRange(*capturedRanges));
    }];


}

#pragma mark - 15.定义，解析json数据
{
    #define TX_APP_DELEGATE ((AppDelegate*)[[UIApplication sharedApplication] delegate])

    /**
     *  Secure String
     */
    #define TX_STRING(object)  (object == nil ? @"":[NSString stringWithFormat:@"%@", object])
    #define TX_ARRAY(object)  ( ((object == nil) || ([object isEqual:[NSNull null]])) ? @[] : object )
    #define TX_DICTIONARY(object)  ( ((object == nil) || ([object isEqual:[NSNull null]])) ? @{} : object )
    #define TX_DIC_VALUE(dic, key) ( (!dic || ![dic isKindOfClass:[NSDictionary class]] || [dic valueForKey:key] == nil || [dic valueForKey:key] == [NSNull null]) ? @"" : [dic valueForKey:key] )
    //解析
    NSString *code = TX_STRING([jsonObj objectForKey:@"code"]);//字符
    NSDictionary* arrData = [jsonObj objectForKey:@"data"];    //字典


}

#pragma mark - 16.清除缓存
{
    //创建下载地址
    -(NSString *)downloadCachedDir
    {
        NSFileManager* fileManager = [NSFileManager defaultManager];
        
        NSString* cachedDir = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES)lastObject];
        NSString* createdPath = [NSString stringWithFormat:@"%@/annex", cachedDir];
        if (![[NSFileManager defaultManager] fileExistsAtPath:createdPath])
        {
            [fileManager createDirectoryAtPath:createdPath withIntermediateDirectories:YES attributes:nil error:nil];
        }
        
        return createdPath;
    }

    //计算缓存大小，即下载的附件的大小
    NSString* path = [[DownloadService shareInstance] downloadCachedDir];
    NSFileManager* fileManager = [NSFileManager defaultManager];
    unsigned long long folderSize = 0.0;
    if ([fileManager fileExistsAtPath:path])
    {
        NSArray* childerFiles = [fileManager subpathsAtPath:path];
        for (NSString* fileName in childerFiles)
        {
            NSString* absolutePath = [path stringByAppendingPathComponent:fileName];
            folderSize += [self fileSizeAtPath:absolutePath];
        }
    }
    if (folderSize == 0.0){
        cell.numberTextLab.hidden = YES;
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        cell.userInteractionEnabled = NO;
    } else if (folderSize/1024/1024 >= 1) {
        cell.numberTextLab.text = [NSString stringWithFormat:@"%@M",[self showFloatValue:folderSize/1024/1024]];
    } else {
        cell.numberTextLab.text = @"小于1M";
    }

}

#pragma mark - 17.文件机制

{
    当我们创建应用程序时，在每个沙盒中含有三个文件，分别是Document、Library和temp。
   // Document：一般需要持久的数据都放在此目录中，可以在当中添加子文件夹，iTunes备份和恢复的时候，会包括此目录。
    NSArray  *paths = NSSearchPathDorDirectoriesInDomains(NSDocumentDicrectory,, NSUserDomainMark, YES);
    *docPath = [paths lastObject];
    //Library：设置程序的默认设置和其他状态信息
    NSArray *paths = NSSearchPathForDirectoriseInDomains(NSLibraryDirectory, NSUserDomainMask, YES);
    //获取Library中的Cache   存放缓存文件
    NSArray *paths = NSSearchPathForDirectoriseInDomains(NSCachesDirectory, NSUserDomainMask, YES);
    //temp：创建临时文件的目录，当iOS设备重启时，文件会被自动清除
    NSString *temp = NSTemporaryDirectory( );
    
    Documents：苹果建议将程序中建立的或在程序中的关键用户数据和应用程序数据文件保存在该目录下，这个目录下的文件可以进行数据共享，iTunes备份和恢复的时候会包括此目录；
    关键用户数据是指你的App不能重造的数据(用户生成的数据)，例如用户接收到的文档或者编辑的文件。
    Documents/Inbox：此路径主要是你的应用调用的系统组件（例如文件编辑、邮件等）操作的目录，你只有读取和删除的权限，如果想要修改这个目录下的文件，需要先将文件从中拷贝出来。
    
    Library：苹果建议将程序中非用户数据的文件（程序的默认设置或其它状态信息）存储在此路径下，iTunes备份和恢复的时候会包括此目录。你不应该使用这个目录来存储用户数据文件；
    Library/Caches：存放缓存文件，iTunes不会备份此目录，此目录下文件不会在应用退出删除
    
    tmp：提供一个即时创建临时文件的地方，iTunes不会备份此目录。

}


#pragma mark - 18.绘图
{
    - (void)drawRect:(CGRect)rect {};//在这个方法里面绘制
    
    //1.获取图形上下文
     CGContextRef ctx = UIGraphicsGetCurrentContext();
    
    //直线
    CGContextMoveToPoint(context, 20, 20);
    CGContextAddLineToPoint(context, 200,20);
    CGContextStrokePath(context);
    CGContextAddLineToPoint(ctx, endX, endY);
    //边框宽度
    CGContextSetLineWidth(currentContext,5.0f);
    //设置填充色
    [[UIColor whiteColor] setFill];
    //设置边框颜色
    [[UIColor whiteColor] setStroke];
    
    //画圆
    CGContextAddEllipseInRect(ctx, CGRectMake(100, 100, 50, 50));
    //指定上下文中显示内容的范围
    CGContextClip(ctx);
    //3.渲染
    CGContextStrokePath(ctx);
    
    //画四边形
    CGContextAddRect(ctx, CGRectMake(200, 100, 100, 100));
    CGContextSaveGState(ctx);
    
    //画圆弧
    CGContextAddArc(ctx, topX, topY, topRadius, -M_PI, 0, 0);
    //关闭路径
    CGContextClosePath(ctx);

}

#pragma mark - 19.CGAffineTransform
{
    CGAffineTransformMakeRotation（旋转）、CGAffineTransformMakeScale（缩放）、CGAffineTransformMakeTranslation（移动）
    
    用于在原来的角度、缩放、移动位置的基础上做出修改：CGAffineTransformRotate、CGAffineTransformScale、CGAffineTransformTranslate
    
    //旋转
    - (IBAction)rotationButtonPressed:(id)sender
    {
        self.imageView.transform = CGAffineTransformRotate(self.imageView.transform, M_PI_4);
    }
    //缩放
    - (IBAction)scaleButtonPressed:(id)sender
    {
        self.imageView.transform = CGAffineTransformScale(self.imageView.transform, 0.9, 0.9);
        //在原来的基础上等同于上边
        CGAffineTransform newTransform =  CGAffineTransformScale(self.tqssBtn.transform, 0.92, 0.92);
        [self.tqssBtn setTransform:newTransform];
    }
    //移动
    - (IBAction)moveButtonPressed:(id)sender
    {
        _imageView.transform = CGAffineTransformTranslate(self.imageView.transform, 0, 10);
    }
}

#pragma mark - 20.__block
{
    __block 的标记告诉编译器，这个变量在 block 里面需要做特殊处理。

    一般来说，在 block 中用的变量值是被复制过来的，所以对于变量本身的修改并不会影响这个变量的真实值。而当我们用 __block 标记的时候，表示在 block 中的修改对于 block 外也是有效地。
}

#pragma mark - 21.分割字符串
{
    //将字符串分割成一个数组
    NSArray* arr = [appconment componentsSeparatedByString:@"________"];

}

#pragma mark - 22.多个线程同时调用方法的时候,保证只有一个线程在使用该方法.
{
    //单例
    方法一:
    static Singleton *singleton = nil ;
    
    + (Singleton *)defaultSingleton
    {
        // 方法锁,作用为:当多个线程同时调用方法的时候,保证只有一个线程在使用该方法.例如:A和B同时调用defaultSingleton方法,如果A正在使用该方法,那么B就不能调用,直到A使用完成,B才会执行该方法.这个也保证单例对象的唯一性,避免初始化方法被同时多次执行.
        @synchronized(self)
        {
            if (singleton == nil)
            {
                singleton = [[Singleton alloc] init] ;
            }
        }
        return singleton ;
    }
    
    
    方法二:
    static Singleton *singleton = nil;
    
    +(Singleton *)shareSingleton{
        
        // 当多个线程同时访问该资源的时候，能保护该资源在同一时刻只有一个线程访问.保证了单例对象的唯一性
        static dispatch_once_t onceToken;
        dispatch_once(&onceToken, ^{
            if (singleton == nil) {
                singleton = [[Singleton alloc] init];
            }
        });
        return singleton;
    }
}

#pragma mark - 23.webView
{
    _detailWebView.backgroundColor = [UIColor clearColor];
    _detailWebView.opaque = NO; //这个属性设置之后才能设置颜色
}

#pragma mark - 24.GCD NSOperation
{
    
    // http://www.cnblogs.com/wendingding/p/3809042.html
    
    Grand Central Dispatch (GCD)是Apple开发的一个多核编程的解决方法。
    dispatch_async 异步操作,会并发执行,无法确定任务的执行顺序;
    dispatch_sync 同步操作,会依次顺序执行,能够决定任务的执行顺序.
    
    //  后台执行：
    dispatch_async(dispatch_get_global_queue(0, 0), ^{
        // something
    });
    
    // 主线程执行：
    dispatch_async(dispatch_get_main_queue(), ^{
        // something
    });

    // 一次性执行：
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        // code to be executed once
    });
    
    // 延迟2秒执行：
    double delayInSeconds = 2.0;
    dispatch_time_t popTime = dispatch_time(DISPATCH_TIME_NOW, delayInSeconds * NSEC_PER_SEC);
    dispatch_after(popTime, dispatch_get_main_queue(), ^(void){
        // code to be executed on the main queue after delay
    });
    
    // 合并汇总结果   队列组
    dispatch_group_t group = dispatch_group_create();
    dispatch_group_async(group, dispatch_get_global_queue(0,0), ^{
        // 并行执行的线程一
    });
    dispatch_group_async(group, dispatch_get_global_queue(0,0), ^{
        // 并行执行的线程二
    });
    dispatch_group_notify(group, dispatch_get_global_queue(0,0), ^{
        // 汇总结果  等前面的异步操作都执行完毕后，回到主线程...
    });
    
    
    iOS的三种多线程技术特点:
    
    1.NSThread:
    
    1> 使用NSThread对象建立一个线程非常方便;
    
    2> 但是!要使用NSThread管理多个线程非常困难,不推荐使用;
    
    3> 技巧!使用[NSThread currentThread]跟踪任务所在线程,适用于这三种技术.
    
    2.NSOperation/NSOperationQueue:
    
    1> 是使用GCD实现的一套Objective-C的API;
    
    2> 是面向对象的多线程技术;
    
    3> 提供了一些在GCD中不容易实现的特性,如:限制最大并发数量,操作之间的依赖关系.
    
    3.GCD---Grand Central Dispatch:
    
    1> 是基于C语言的底层API;
    
    2> 用Block定义任务,使用起来非常灵活便捷;
    
    3> 提供了更多的控制能力以及操作队列中所不能使用的底层函数.
    
    iOS的开发者需要了解三种多线程技术的基本使用,因为在实际开发中会根据实际情况选择不同的多线程技术.
    

    
    
    {
        //https://www.jianshu.com/p/4b1d77054b35
        1.
       //    NSOperation
        //创建操作对象，封装要执行的任务
            //NSInvocationOperation   封装操作
            NSInvocationOperation *operation=[[NSInvocationOperation alloc]initWithTarget:self selector:@selector(test) object:nil];
    
            //执行操作
            [operation start];
        
        
        2.
        //创建NSBlockOperation操作对象  添加封装操作数为几，线程数就为几，即为异步操作
        NSBlockOperation *operation=[NSBlockOperation blockOperationWithBlock:^{
            NSLog(@"NSBlockOperation------%@",[NSThread currentThread]);
        }];
        
        //添加操作
        [operation addExecutionBlock:^{
            NSLog(@"NSBlockOperation1------%@",[NSThread currentThread]);
        }];
        
        [operation addExecutionBlock:^{
            NSLog(@"NSBlockOperation2------%@",[NSThread currentThread]);
        }];
        
        // 只要NSBlockOperation封装的操作数 > 1,就会异步执行操作
        //开启执行操作
        [operation start];
        
        
        3.
        NSOperationQueue的作⽤：NSOperation可以调⽤start⽅法来执⾏任务,但默认是同步执行的
        
        如果将NSOperation添加到NSOperationQueue(操作队列)中,系统会自动异步执行NSOperation中的操作
        
        //创建NSInvocationOperation对象，封装操作
        NSInvocationOperation *operation1=[[NSInvocationOperation alloc]initWithTarget:self selector:@selector(test1) object:nil];
        NSInvocationOperation *operation2=[[NSInvocationOperation alloc]initWithTarget:self selector:@selector(test2) object:nil];
        //创建对象，封装操作
        NSBlockOperation *operation3=[NSBlockOperation blockOperationWithBlock:^{
            NSLog(@"NSBlockOperation3--1----%@",[NSThread currentThread]);
        }];
        [operation3 addExecutionBlock:^{
            NSLog(@"NSBlockOperation3--2----%@",[NSThread currentThread]);
        }];
        
        //创建NSOperationQueue
        NSOperationQueue * queue=[[NSOperationQueue alloc]init];
        //把操作添加到队列中
        [queue addOperation:operation1];
        [queue addOperation:operation2];
        [queue addOperation:operation3];
        //系统自动将NSOperationqueue中的NSOperation对象取出，将其封装的操作放到一条新的线程中执行
        
        
        4.
        操作优先级
        （1）设置NSOperation在queue中的优先级,可以改变操作的执⾏优先级
        
        - (NSOperationQueuePriority)queuePriority;
        - (void)setQueuePriority:(NSOperationQueuePriority)p;
        
        （2）优先级的取值
        
        NSOperationQueuePriorityVeryLow = -8L,
        
        NSOperationQueuePriorityLow = -4L,
        
        NSOperationQueuePriorityNormal = 0,
        
        NSOperationQueuePriorityHigh = 4,
        
        NSOperationQueuePriorityVeryHigh = 8 
        
        说明：优先级高的任务，调用的几率会更大。
        
        5.
        //设置操作依赖
        //先执行operation2，再执行operation1，最后执行operation3
        [operation3 addDependency:operation1];
        [operation1 addDependency:operation2];
    }
}

#pragma mark - 25.支付
{
    //支付宝支付
    // http://www.bubuko.com/infodetail-1121251.html
}

#pragma mark - 26.RunLoop 
{
    // http://www.cocoachina.com/ios/20150601/11970.html
    
    
    Run loop，正如其名，loop表示某种循环，和run放在一起就表示一直在运行着的循环。实际上，run loop和线程是紧密相连的，可以这样说run loop是为了线程而生，没有线程，它就没有存在的必要
    
    利用 RunLoop 实现自动释放池、延迟回调、触摸事件、屏幕刷新等功能
    RunLoop 实际上就是一个对象，这个对象管理了其需要处理的事件和消息，并提供了一个入口函数来执行上面 Event Loop 的逻辑
    
    runloop可以理解为cocoa下的一种消息循环机制，用来处理各种消息事件，我们在开发的时候并不需要手动去创建一个runloop，因为框架为我们创建了一个默认的runloop,通过[NSRunloop currentRunloop]我们可以得到一个当前线程下面对应的runloop对象，不过我们需要注意的是不同的runloop之间消息的通知方式。
    
    接着上面的话题，在开启一个NSTimer实质上是在当前的runloop中注册了一个新的事件源，而当scrollView滚动的时候，当前的MainRunLoop是处于 /*UITrackingRunLoopMode */ 的模式下，在这个模式下，是不会处理/*NSDefaultRunLoopMode */ 的消息(因为RunLoop Mode不一样)，要想在scrollView滚动的同时也接受其它runloop的消息，我们需要改变两者之间的runloopmode.
    简单的说就是NSTimer不会开启新的进程，只是在Runloop里注册了一下，Runloop每次loop时都会检测这个timer，看是否可以触发。当Runloop在A mode，而timer注册在B mode时就无法去检测这个timer，所以需要把NSTimer也注册到A mode，这样就可以被检测到
}

#pragma mark - 27.修饰符

{
    nonatomic和atomic对比
    atomic：原子属性(线程安全)，就是针对多线程设计的，是默认属性
    多个线程写入属性时，保证同一时间只有一个线程能够执行写入操作
    nonatomic：非线程安全，适合内存小的移动设备
    
    assign、retain、copy：决定为该属性生成的赋值函数的类型。assign生成的赋值函数只是简单地为变量进行赋值。retain生成的赋值函数在赋值到变量的时候会保留传入到参数。copy生成的存取函数会复制传入的参数到成员变量。默认值是assign。
    Copy其实是建立了一个相同的对象，而retain不是   Copy 到另外一个NSString 之后，地址为0×2222 ，内容相同，新的对象retain为1 ，旧有对象没有变化
    retain 到另外一个NSString 之后，地址相同（建立一个指针，指针拷贝），内容当然相同，这个对象的retain值+1
    也就是说，retain 是指针拷贝，copy 是内容拷贝
    
    {//NSString 被修饰的的时候   http://www.cocoachina.com/ios/20150512/11805.html
        当源字符串是NSString时，由于字符串是不可变的，所以，不管是strong还是copy属性的对象，都是指向源对象，copy操作只是做了次浅拷贝。
        
        当源字符串是NSMutableString时，strong属性只是增加了源字符串的引用计数，而copy属性则是对源字符串做了次深拷贝，产生一个新的对象，且copy属性对象指向这个新的对象。另外需要注意的是，这个copy属性对象的类型始终是NSString，而不是NSMutableString，因此其是不可变的。
    }

}


#pragma mark - 28.CALayer
{
    //CALayer
    
    {
        //在view的图层上添加一个image，contents表示接受内容
        self.customView.layer.contents=(id)[UIImage imageNamed:@"me"].CGImage;
        
        //设置阴影的颜色
        self.customView.layer.shadowColor=[UIColor blackColor].CGColor;
        //设置阴影的偏移量，如果为正数，则代表为往右边偏移
        self.customView.layer.shadowOffset=CGSizeMake(15, 5);
        //设置阴影的透明度(0~1之间，0表示完全透明)
        self.customView.layer.shadowOpacity=0.6;
        
        //设置超过子图层的部分裁减掉 设置阴影就会失效
        //UI框架中使用的方法
        //    self.customView.clipsToBounds=YES;
        self.customView.layer.masksToBounds=YES;
        
        
        //通过uiview设置（2D效果）
        12 //    self.iconView.transform=CGAffineTransformMakeTranslation(0, -100);
        13     //通过layer来设置（3D效果,x，y，z三个方向）
        14 //    self.iconView.layer.transform=CATransform3DMakeTranslation(100, 20, 0);
        15
        16     //通过KVC来设置
        17 //    NSValue *v=[NSValue valueWithCATransform3D:CATransform3DMakeTranslation(100, 20, 0)];
        18 //    [self.iconView.layer setValue:v forKeyPath:@"transform"];
        19 //    //如果是只需要设置在某一个方向上的移动，可以参考下面的代码
        20 //    //在x的方向上向左移动100
        21 //    [self.iconView.layer setValue:@(-100) forKeyPath:@"transform.translation.x"];
        22
        23     //旋转
        24     self.iconView.layer.transform=CATransform3DMakeRotation(M_PI_4, 1, 1, 0.5);
        
    }

}


#pragma mark - 29.响应者链
{
    一般来说，第一响应者是个视图对象或者其子类对象，当其被触摸后事件被交由它处理，如果它不处理，事件就会被传递给它的视图控制器对象viewcontroller（如果存在），然后是它的父视图（superview）对象（如果存在），以此类推，直到顶层视图。接下来会沿着顶层视图（top view）到窗口（UIWindow对象）再到程序（UIApplication对象）。如果整个过程都没有响应这个事件，该事件就被丢弃。一般情况下，在响应者链中只要由对象处理事件，事件就停止传递。
    
    一个典型的相应路线图如：
    First Responser -- > The Window -- >The Application -- > App Delegate
}


#pragma mark - 30.NSTimer
{
    //1.
    {
        NSInvocation * invo = [NSInvocation invocationWithMethodSignature:[[self class] instanceMethodSignatureForSelector:@selector(init)]];
        [invo setTarget:self];
        [invo setSelector:@selector(myLog)];
        NSTimer * timer = [NSTimer timerWithTimeInterval:1 invocation:invo repeats:YES];
        //加入主循环池中
        [[NSRunLoop mainRunLoop]addTimer:timer forMode:NSDefaultRunLoopMode];
        //开始循环
        [timer fire];
    }
    //2.
    {
         NSTimer * timer = [NSTimer scheduledTimerWithTimeInterval:1 invocation:invo repeats:YES];
        
        NSTimer * timer = [NSTimer timerWithTimeInterval:1 target:self selector:@selector(myLog) userInfo:nil repeats:NO]

        NSTimer * timer = [NSTimer scheduledTimerWithTimeInterval:1 target:self selector:@selector(myLog:) userInfo:@"123" repeats:YES]
        
        NSTimer * timer = [[NSTimer alloc]initWithFireDate:[NSDate distantPast] interval:1 target:self selector:@selector(myLog:) userInfo:nil repeats:YES];
        [[NSRunLoop mainRunLoop]addTimer:timer forMode:NSDefaultRunLoopMode];

    }
    1、参数repeats是指定是否循环执行，YES将循环，NO将只执行一次。
    
    2、timerWithTimeInterval这两个类方法创建出来的对象如果不用 addTimer: forMode方法手动加入主循环池中，将不会循环执行。并且如果不手动调用fair，则定时器不会启动。
    
    3、scheduledTimerWithTimeInterval这两个方法不需要手动调用fair，会自动执行，并且自动加入主循环池。
    
    4、init方法需要手动加入循环池，它会在设定的启动时间启动。
    //释放
    if (timer.isValid) {
        [timer invalidate];
    }
    timer=nil;
}


#pragma mark - 31.网络请求，原始

{
    1）NSURL：请求地址
    
    （2）NSURLRequest：封装一个请求，保存发给服务器的全部数据，包括一个NSURL对象，请求方法、请求头、请求体....
    
    （3）NSMutableURLRequest：NSURLRequest的子类
    
    （4）NSURLConnection：负责发送请求，建立客户端和服务器的连接。发送NSURLRequest的数据给服务器，并收集来自服务器的响应数据
    
    
    // 1.同步请求 get
        1.设置请求路径
        NSString *urlStr=[NSString stringWithFormat:@"http://192.168.1.53:8080/MJServer/login?username=%@&pwd=%@",self.username.text,self.pwd.text];
        NSURL *url=[NSURL URLWithString:urlStr];
        //    2.创建请求对象
        NSURLRequest *request=[NSURLRequest requestWithURL:url];
        //    3.发送请求
        //发送同步请求，在主线程执行
        NSData *data=[NSURLConnection sendSynchronousRequest:request returningResponse:nil error:nil];
    //2.异步请求 get
    //3.1发送异步请求
    //创建一个队列（默认添加到该队列中的任务异步执行）
    //    NSOperationQueue *queue=[[NSOperationQueue alloc]init];
    //获取一个主队列
//    {
//        NSOperationQueue *queue=[NSOperationQueue mainQueue];
//        [NSURLConnection sendAsynchronousRequest:request queue:queue completionHandler:^(NSURLResponse *response, NSData *data, NSError *connectionError) {
//            NSLog(@"--block回调数据--%@---%d", [NSThread currentThread],data.length);
//            //解析data
//            NSDictionary *dict=[NSJSONSerialization JSONObjectWithData:data options:NSJSONReadingMutableLeaves error:nil];
//        }
//    }
    
}

     
#pragma mark - 32.网络请求 ASI
{
    // http://www.cnblogs.com/wendingding/p/3950027.html
    
    /**
     * POST   ASIFormDataRequest
     */
    {
        NSString *postURL = [NSString stringWithFormat:@"http://xxxxxx.php"];
        
        ASIFormDataRequest *request = [[ASIFormDataRequest alloc] initWithURL:[NSURL URLWithString:postURL]];
        
        [request addPostValue:myModel forKey:@"mod"];
        
        [request addPostValue:myAllData forKey:@"data"];
        
        [request startSynchronous];
    }
    

    /**
     *  异步请求的第一种方式：设置代理，用代理方法监听
     */
    -(void)async1
    {
        //1.创建网络请求（GET）
        NSURL *url=[NSURL URLWithString:@"http://127.0.0.1:8080/MJServer/login?username=123&pwd=123"];
        self.request=[ASIHTTPRequest requestWithURL:url];
        //设置网络请求的延时为10秒钟
        self.request.timeOutSeconds=10;
        
        //2.设置代理
        self.request.delegate=self;
        
        
        //3.发送请求(异步请求)
        [self.request startAsynchronous];
    }
    
    //pragma mark-异步请求的代理方法
    //请求开始的时候调用
    -(void)requestStarted:(ASIHTTPRequest *)request
    {
        
    }
    //接收到服务器返回的数据时调用（数据量比较大的时候，这个方法会被调用多次，每次只能拿到部分数据）
    -(void)request:(ASIHTTPRequest *)request didReceiveData:(NSData *)data
    {
        
    }
    //请求结束的时候调用（在该方法中拿到最终的数据）
    -(void)requestFinished:(ASIHTTPRequest *)request
    {
        //request.responseData:服务器返回的所有数据，这个data已经拼接了接收到的所有数据
    }
    //发送网络请求失败的时候调用
    -(void)requestFailed:(ASIHTTPRequest *)request
    {
    }
    
    
    /**
     *  异步请求的第二种方式：selector,以设置代理为基本前提
     */
    -(void)async2
    {
        //1.创建网络请求（GET）
        NSURL *url=[NSURL URLWithString:@"http://127.0.0.1:8080/MJServer/login?username=123&pwd=123"];
        self.request=[ASIHTTPRequest requestWithURL:url];
        //设置网络请求的延时为10秒钟
        self.request.timeOutSeconds=10;
        
        //2.设置代理
        self.request.delegate=self;
        
        //通过selector的方法，当请求开始的时候，由请求的代理即控制器调用start方法进行监听
        //说明：该方法会覆盖代理方法
        [self.request setDidStartSelector:@selector(start)];
        
        //3.发送请求(异步请求)
        [self.request startAsynchronous];
    }
    
    -(void)start
    {
        NSLog(@"该方法会覆盖代理方法中得对应方法");
    }
    
    
    
    /**
     *  异步请求的第三种方式：使用block回调
     */
    -(void)async3
    {
        //1.创建网络请求（GET）
        NSURL *url=[NSURL URLWithString:@"http://127.0.0.1:8080/MJServer/login?username=123&pwd=123"];
        self.request=[ASIHTTPRequest requestWithURL:url];
        //设置网络请求的延时为10秒钟
        self.request.timeOutSeconds=10;
        
        //2.使用block回调监听
        [self.request setStartedBlock:^{
            //请求开始的时候调用
        }];
        [self.request setFailedBlock:^{
            //请求失败的时候调用
        }];
        [self.request setDataReceivedBlock:^(NSData *data) {
            //开始接收数据的时候调用
        }];
        [self.request setCompletionBlock:^{
            //请求成功完成的时候调用
        }];
        
        //3.发送请求(异步请求)
        [self.request startAsynchronous];
    }
    
    
    /**
     * 同步请求
     */
    -(void)sync
    {
        //1.创建网络请求（GET）
        NSURL *url=[NSURL URLWithString:@"http://127.0.0.1:8080/MJServer/login?username=123&pwd=123"];
        ASIHTTPRequest *request=[ASIHTTPRequest requestWithURL:url];
        //设置网络请求的延时为10秒钟
        request.timeOutSeconds=10;
        
        //2.发送请求(同步请求)
        [request startSynchronous];
        
        
        //3.检测服务器返回的结果
        if (request.error) {//请求出错，比如超时
            NSLog(@"请求超时，错误信息为%@",request.error);
        }else//请求成功
        {
            //打印状态码和状态信息
            NSLog(@"状态码---%d，状态信息---%@",request.responseStatusCode, request.responseStatusMessage);
            //打印返回的数据的长度
            NSLog(@"返回数据的长度--%d",request.responseData.length);
            //将返回的数据转换为字符串
            NSLog(@"返回的数据---%@",request.responseString);
            
            //将服务器返回的数据解析为字典
            NSDictionary *dictionary = [NSJSONSerialization JSONObjectWithData:request.responseData options:NSJSONReadingMutableLeaves error:Nil];
            NSLog(@"%@",dictionary);
        }
    }
    
    /**
     * 上传
     */
    {
        向服务器端上传数据
        ASIFormDataRequest ，模拟 Form表单提交，其提交格式与 Header会自动识别。
        没有文件：application/x-www-form-urlencoded
        有文件：multipart/form-data
        
        ASIFormDataRequest *request = [ASIFormDataRequest requestWithURL:url];
        [request setPostValue:@"Ben" forKey:@"first_name"];
        [request setPostValue:@"Copsey" forKey:@"last_name"];
        [request setFile:@"/Users/ben/Desktop/ben.jpg" forKey:@"photo"];
        [request addData:imageData withFileName:@"george.jpg" andContentType:@"image/jpeg"forKey:@"photos"];   //图片
        如果要发送自定义数据：
        
        ASIHTTPRequest *request = [ASIHTTPRequest requestWithURL:url];
        [request appendPostData:[@"This is my data" dataUsingEncoding:NSUTF8StringEncoding]];
        // Default becomes POST when you use appendPostData: / appendPostDataFromFile: / setPostBody:
        [request setRequestMethod:@"PUT"];
    }
    /**
     * 文件下载
     */
    {
        -(void)download1
        {
             // http://www.cnblogs.com/wendingding/p/3961681.html
             1）创建请求对象；
            （2）设置下载文件保存的路径；
            （3）发送下载文件的网络请求（异步）。
            //1.创建请求对象
            NSURL *url=[NSURL URLWithString:@"http://127.0.0.1:8080/MJServer/resources/video.zip"];
            ASIHTTPRequest *request=[ASIHTTPRequest requestWithURL:url];
            
            //2.设置下载文件保存的路径
            NSString *cachepath=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES)lastObject];
            NSString *filename=[cachepath stringByAppendingPathComponent:@"video.zip"];
            request.downloadDestinationPath=filename;
            NSLog(@"%@",filename);
            
            //3.发送网络请求（异步）
            [request startAsynchronous];
            
            //4.当下载完成后通知
            [request setCompletionBlock:^{
                NSLog(@"下载成功");
            }];
        }
        
        //.设置下载进度的代理
        request.downloadProgressDelegate=self.progress;
        //设置支持断点下载的代码如下：
        request.allowResumeForFileDownloads=YES;
        //取消下载的代码为：
        [request clearDelegatesAndCancel];

        // 有两个回调方法可以获取请求进度，
        1，downloadProgressDelegate，可以获取下载进度
        2，uploadProgressDelegate，可以获取上传进度
    }
}

#pragma mark - 33.判断网络状态  Reachability
         
{
    
    // 监测网络情况
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(reachabilityChanged:)
                                                 name: kReachabilityChangedNotification
                                               object: nil];
    
    Reachability *r = [Reachability reachabilityWithHostName:@“www.apple.com”];
    switch ([r currentReachabilityStatus]) {
        case NotReachable:
            // 没有网络连接
            break;
        case ReachableViaWWAN:
            // 使用3G网络
            break;
        case ReachableViaWiFi:
            // 使用WiFi网络
            break;
    }
    // 是否wifi
    + (BOOL) IsEnableWIFI {
        return ([[Reachability reachabilityForLocalWiFi] currentReachabilityStatus] != NotReachable);
    }
    
    // 是否3G
    + (BOOL) IsEnable3G {
        return ([[Reachability reachabilityForInternetConnection] currentReachabilityStatus] != NotReachable);
    }
}

#pragma mark - 34.单例
         
{
        // 单例模式
        + (TXTelService *)sharedInstance
        {
            static TXTelService *sharedObject = nil;
            
            static dispatch_once_t onceToken;
            dispatch_once(&onceToken, ^{
                sharedObject = [[TXTelService alloc] init];
            });
            
            return sharedObject;
        }
    
    
    // [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES)[0] \
     stringByAppendingPathComponent:path]     TX_DOCUMENT_PATH
        // UserData 存储为plist
        {
            + (NSDictionary *)loadFromLocalData:(NSString *)name
            {
                NSString *fileName = [NSString stringWithFormat:@"%@.plist", name];
                NSString *filePath = TX_DOCUMENT_PATH(fileName);
                
                return [[NSDictionary alloc]initWithContentsOfFile:filePath];
            }
            
            + (void)saveToLocalData:(NSDictionary *)dict withSaveName:(NSString *)saveName
            {
                NSString *fileName = [NSString stringWithFormat:@"%@.plist", saveName];
                NSString *filePath = TX_DOCUMENT_PATH(fileName);
                BOOL ret=[dict writeToFile:filePath atomically:YES];
                if (!ret) {
                    TXLog(@"write file failed!");
                }
            }

        }

}
    
#pragma mark - 35.地图（高德）
         
    {
        //设置地图
        [MAMapServices sharedServices].apiKey = APIKey;
        [AMapLocationServices sharedServices].apiKey = APIKey;//定位key
        
        mapViews = [[MAMapView alloc]initWithFrame:CGRectMake(0, 0, CGRectGetWidth(self.view.bounds), CGRectGetHeight(self.view.bounds))];
        [self.view addSubview:mapViews];
        mapViews.delegate = self;
        
        
        // mapViews.showsUserLocation = YES; //设置定位当前位置
        [mapViews setUserTrackingMode:1 animated:YES]; //设置跟随定位
        [mapViews setMapType:MAMapTy  peStandard]; //设置地图类型
        
        [mapViews setZoomLevel:16.1 animated:YES];//设置缩放级别 就是显示的高度
        
        [mapViews setCenterCoordinate:annotationNow.coordinate];//设置中心为指定坐标位置

    
        //定位
        {
            //设置定位  一次定位
            locationManager = [[AMapLocationManager alloc]init];
            locationManager.delegate = self;
            //[locationManager startUpdatingLocation];//开启连续定位
            // [locationManager stopUpdatingLocation];//停止连续定位
            [locationManager setDesiredAccuracy:kCLLocationAccuracyBest];//设置定位精度
            
            [locationManager requestLocationWithReGeocode:YES completionBlock:^(CLLocation *location, AMapLocationReGeocode *regeocode, NSError *error) {
                
                //如果开启连续定位就无效
                if (error)
                {
                    NSLog(@"error == %@", error.localizedDescription);
                }
                if (location)
                {
                    // annotationNow = [[MAPointAnnotation alloc]init];
                    [annotationNow setCoordinate:location.coordinate];//经纬度
                    NSNumber *latitude = [NSNumber numberWithDouble:location.coordinate.latitude];
                    NSNumber *longitude = [NSNumber numberWithDouble:location.coordinate.longitude];
                    NSLog(@" latitude == %@, longitude == %@", latitude, longitude);
                }
                
            }];

        }
        
        {
            //大头针
            
            MAPointAnnotation //数据格式
            MAPinAnnotationView  // 提供类似大头针效果的annotation view
            
            MAUserLocationRepresentation //精度圈
            {
                //定位的时候显示的光圈自定义
                - (void)mapView:(MAMapView *)mapView didAddAnnotationViews:(NSArray *)views
                {
                    MAAnnotationView *view = views[0];
                    if ([view.annotation isKindOfClass:[MAUserLocation class]])
                    {
                        MAUserLocationRepresentation *pre = [[MAUserLocationRepresentation alloc]init];
                        pre.fillColor = [UIColor colorWithRed:0.9 green:0.1 blue:0.1 alpha:0.3];
                        pre.image = [UIImage imageNamed:@""];
                        pre.lineWidth = 1;
                        pre.lineDashPattern = @[@6,@3];
                        [mapViews updateUserLocationRepresentation:pre];
                        view.calloutOffset = CGPointMake(0, 0);
                    }
                }
            }
            
        }
        
        //搜索，提示搜索（就是需要的搜索关键字搜索例如：饭店、银行等）
        {
            search = [[AMapSearchAPI alloc]init];
            search.delegate = self;
            AMapInputTipsSearchRequest *tipsRequest = [[AMapInputTipsSearchRequest alloc]init];
            tipsRequest.keywords = @"肯德基";
            tipsRequest.city = @"西安";
            [search AMapInputTipsSearch:tipsRequest];
            //回调函数
            - (void)onInputTipsSearchDone:(AMapInputTipsSearchRequest *)request response:(AMapInputTipsSearchResponse *)response

        }

    }
   

#pragma mark - 36. 数据解析 XML  JSON
{
    
    
    // http://www.jianshu.com/p/a54d367adb2a
    
    // SAX 和DOM
    SAX（Simple API for XML，基于事件驱动的解析方式，逐行解析数据，采用协议回调机制）
    DOM（Document Object Model ，文档对象模型。解析时需要将XML文件整体读入，并且将XML结构化成树状，使用时再通过树状结构读取相关数据，查找特定节点，然后对节点进行读或写）。
        
        
    /**
     *  NSXMLParse   类库采用第一种方式  SAX
     */
        
        一边读取文档一边解析数据
    {
        //获取数据
        NSData *data = [NSData dataWithContentsOfFile:path];
        self.par = [[NSXMLParser alloc]initWithData:data];
        //添加代理
        self.par.delegate = self;
        
        
        //代理方法 实现解析
        
        //开始解析
        - (void)parserDidStartDocument:(NSXMLParser *)parser{
            NSLog(@"parserDidStartDocument...");
        }
        //准备节点
        - (void)parser:(NSXMLParser *)parser didStartElement:(NSString *)elementName namespaceURI:(nullable NSString *)namespaceURI qualifiedName:(nullable NSString *)qName attributes:(NSDictionary<NSString *, NSString *> *)attributeDict{
            
            self.currentElement = elementName;
            
            if ([self.currentElement isEqualToString:@"student"]){
                self.person = [[person alloc]init];
            }
        }
        
        //获取节点内容
        - (void)parser:(NSXMLParser *)parser foundCharacters:(NSString *)string{
            
            if ([self.currentElement isEqualToString:@"pid"]) {
                
                [self.person setPid:string];
            }else if ([self.currentElement isEqualToString:@"name"]){
                [self.person setName:string];
            }else if ([self.currentElement isEqualToString:@"sex"]){
                [self.person setSex:string];
            }else if ([self.currentElement isEqualToString:@"age"]){
                
                [self.person setAge:string];
            }
        }
        
        //解析完一个节点
        - (void)parser:(NSXMLParser *)parser didEndElement:(NSString *)elementName namespaceURI:(nullable NSString *)namespaceURI qualifiedName:(nullable NSString *)qName{
            
            if ([elementName isEqualToString:@"student"]) {
                [self.list addObject:self.person];
            }
            self.currentElement = nil;
        }
        
        //解析结束
        - (void)parserDidEndDocument:(NSXMLParser *)parser{
            NSLog(@"parserDidEndDocument...");
        }
    }
    /**
     * GDataXML DOM
     */
        {
            DOM实现的原理是把整个xml文档一次性读出，放在一个树型结构里。在需要的时候，查找特定节点，然后对节点进行读或写。
            
            GDataXMLDocument *doc = [[GDataXMLDocument alloc]initWithData:data error:nil];
            //获取根节点
            GDataXMLElement *rootElement = [doc rootElement];
            //获取其他节点
            NSArray *students = [rootElement elementsForName:@"student"];
            //初始化可变数组，用来显示到textView
            self.GDatatext = [[NSMutableString alloc]initWithString:@""];
            for (GDataXMLElement *student in students) {
                //获取节点属性
                GDataXMLElement *pidElement = [[student elementsForName:@"pid"] objectAtIndex:0];
                NSString *pid = [pidElement stringValue];
                
                
                GDataXMLElement *nameElement = [[student elementsForName:@"name"] objectAtIndex:0];
                NSString *name = [nameElement stringValue];
                
                
                GDataXMLElement *sexElement = [[student elementsForName:@"sex"] objectAtIndex:0];
                NSString *sex = [sexElement stringValue];
                
                
                GDataXMLElement *ageElement = [[student elementsForName:@"age"] objectAtIndex:0];
                NSString *age = [ageElement stringValue];
                
                //调整一下姿势，添加到可变长字符串~~
                NSString *t = [NSString stringWithFormat:@"学号：%@ 姓名：%@ 性别：%@ 年龄：%@\n", pid, name, sex, age];
                [self.GDatatext appendString:t];
        }
        
        /**
         * JSON    NSJSONSerialization
         */
        {
            苹果官方给出的解析方式是性能最优越
            
            self.dic = [NSJSONSerialization JSONObjectWithData:data options:NSJSONReadingMutableContainers error:nil];
            NSString *title = [self.dic objectForKey:@"original_title"];
        }
}

    
#pragma mark - 37. NSString
{
    [string107 uppercaseString]   //大写
    [string108 lowercaseString]     //小写
    [string107 capitalizedString]   //大写首字母
    [string10 stringByAppendingString:string11] == [[NSString alloc] initWithFormat: @"%@%@",string10,string11]     //拼接字符串
    
    //截取
    -substringToIndex:  //从字符串的开头一直截取到指定的位置，但不包括该位置的字符
    -substringFromIndex:    //以指定位置开始（包括指定位置的字符），并包括之后的全部字符
    -substringWithRange: //按照所给出的位置，长度，任意地从字符串中截取子串
    
    //在串中搜索子串
    NSRange range = [string1 rangeOfString:string2];
    int location = range.location;
    int leight = range.length;
    NSString *astring = [[NSString alloc] initWithString:[NSString stringWithFormat:@"Location:%i,Leight:%i",location,leight]];
    
    //在已有字符串后面添加字符
    [String1 appendString:@", I will be adding some character"];
    [String1 appendFormat:[NSString stringWithFormat:@", I will be adding some character"]];
    
    //删除
    [String1 deleteCharactersInRange:NSMakeRange(0, 5)];
    //插入
    [String1 insertString:@"Hi! " atIndex:0];
    //替换
    [String1 replaceCharactersInRange:NSMakeRange(0, 4) withString:@"That"];
    
    // 检查字符串是否以另一个字符串开头- (BOOL) hasPrefix: (NSString *) aString;
    NSString *String1 = @"NSStringInformation.txt";
    [String1 hasPrefix:@"NSString"] = = 1 ?  NSLog(@"YES") : NSLog(@"NO");
    [String1 hasSuffix:@".txt"] = = 1 ?  NSLog(@"YES") : NSLog(@"NO");
    
    
    // 字符 切为 数组
    NSString *string = [[NSString alloc] initWithString:@"One,Two,Three,Four"];
    NSArray *array = [string componentsSeparatedByString:@","];
    
    // 数组 切为 字符串
    NSArray *array = [[NSArray alloc] initWithObjects:@"One",@"Two",@"Three",@"Four",nil];
    NSString *string = [array componentsJoinedByString:@","];
    
    
    //比较
    comparer
    1.忽略大小写的比较：    int result = [str1 compare:str2 options:NSCaseInsensitiveSearch];
}


#pragma mark - 38. 细节something
{
    {
        1.typedef enum{
            userSex_Man,
            userSex_Woman
        }userSex;
        //规范写成
        typedef enum(NSInteger, userSex) {
            userSexMan,
            userSexWoman
            
        };
        {
            2.
            用@property声明 NSString、NSArray、NSDictionary 经常使用copy关键字，是因为他们有对应的可变类型：NSMutableString、NSMutableArray、NSMutableDictionary，他们之间可能进行赋值操作，为确保对象中的字符串值不会无意间变动，应该在设置新属性值时拷贝一份。
        }
    }
    
    3. //通过sharedApplication获取该程序的UIApplication对象
    UIApplication *app=[UIApplication sharedApplication];
    app.applicationIconBadgeNumber=123;

    4.新浪分享的时候  出错一般是  other linker flags 添加 -Objc
        或者 添加 imageio.framework 类
    
    
    5.cell设置箭头或者颜色改变
        open属性设置hang的状态
        设置箭头的点击代理，在控制器里实现代理方法，将选中这行的数据源中添加的去掉，遍历整个数组，将其他的修改为1
    - (void)changeCellHeight:(NSInteger)indexPath
    {
        //点击 当前 打开的 cell  直接 关闭 然后 retun
        if ([[cellOpens objectAtIndex:indexPath]integerValue]) {
            [cellOpens replaceObjectAtIndex:indexPath withObject:@"0"];
            [self.myTableView reloadData];
            return;
        }
        //这个是点击一行的时候，不影响其他行的状态
        // 点击 按钮之后 遍历 open 数据源 ，改变里面的值 tableview reload 时候 直接 根据数据源 改变 cell 的属性
        for (int i = 0; i < cellOpens.count; i++) {
            if (i == indexPath) {
                [cellOpens replaceObjectAtIndex:i withObject:@"1"];
            }else {
                [cellOpens replaceObjectAtIndex:i withObject:@"0"];
            }
        }
        [self.myTableView reloadData];
    }
    

}

    
#pragma mark - 38. runtime  运行时  运行时库（Runtime Library

{
    // http://my.oschina.net/panyong/blog/298631
    // http://www.ianisme.com/ios/2019.html
    消息机制
    C++是基于静态类型，而Objective-C是基于动态运行时类型。也就是说用C++编写的程序编译时就直接编译成了可令机器读懂的机器语言；用Objective-C编写的程序不能直接编译成可令机器读懂的机器语言，而是在程序运行的时候，通过Runtime把程序转为可令机器读懂的机器语言
    
    OC的函数调用成为消息发送。属于动态调用过程。在编译的时候并不能决定真正调用哪个函数（事实证明，在编 译阶段，OC可以调用任何函数，即使这个函数并未实现，只要申明过就不会报错。而C语言在编译阶段就会报错）。只有在真正运行的时候才会根据函数的名称找 到对应的函数来调用。
    
    runtime是一套比较底层的纯C语言API, 属于1个C语言库, 包含了很多底层的C语言API。
    在我们平时编写的OC代码中, 程序运行过程时, 其实最终都是转成了runtime的C语言代码, runtime算是OC的幕后工作者
    OC :
    [[Person alloc] init]
    runtime :
    objc_msgSend(objc_msgSend(“Person” , “alloc”), “init”)
    //相关函数
    objc_msgSend : 给对象发送消息
    class_copyMethodList : 遍历某个类所有的方法
    class_copyIvarList : 遍历某个类所有的成员变量
    
     Ivar : 成员变量
    Method : 成员方法
    
    //isa
    每一个对象本质上都是一个类的实例。其中类定义了成员变量和成员方法的列表。对象通过对象的isa指针指向类。
    每一个类本质上都是一个对象，类其实是元类（meteClass）的实例。元类定义了类方法的列表。类通过类的isa指针指向元类。
    所有的元类最终继承一个根元类，根元类isa指针指向本身，形成一个封闭的内循环。
    // http://www.jianshu.com/p/41735c66dccb
    
}
 
#pragma mark - 39. 堆 和 栈

{
    一个由C/C++编译的程序占用的内存分为以下几个部分
    1、栈区（stack）—   由编译器自动分配释放   ，存放函数的参数值，局部变量的值等。其
    操作方式类似于数据结构中的栈。
    
        int   b;
    2、堆区（heap）   —   一般由程序员分配释放，   若程序员不释放，程序结束时可能由OS回
    收   。注意它与数据结构中的堆是两回事，分配方式倒是类似于链表
    
        p1   =   (char   *)malloc(10);
    
    3、全局区（静态区）（static）—，全局变量和静态变量的存储是放在一块的，初始化的
    全局变量和静态变量在一块区域，   未初始化的全局变量和未初始化的静态变量在相邻的另
    一块区域。   -   程序结束后由系统释放。
    4、文字常量区   —常量字符串就是放在这里的。   程序结束后由系统释放
    5、程序代码区—存放函数体的二进制代码。  
}


#pragma mark - 40. 排序算法

{
    
    // http://blog.csdn.net/hguisu/article/details/7776068
   //  冒泡排序：
    临近的数字两两比较，按照从小到大或者大到小的顺序交换位置，第一遍最大或最小的数字就在最后，循环
    - (void)bubbleSort(NSArray *array)
    {
        for (int i = 0; i<array.count; i ++)
        {
            for (int j = 1; j<array.count; j++)
            {
                if (array[i] > array[j]) {
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }
    }
    
    //插入排序
    每次将一个待排序的记录，按其关键字大小插入到前面已经排好序的子序列中的适当位置，直到全部记录插入完成为止。
    - (void)insertSort(NSArray *arr)
    {
        for (int i = 1; i < arr.count; i++)
        {
            if (arr[i - 1] > arr[i])
            {
                int temp = arr[i];
                int j = 1;
                
                while (j > 0 && arr[j-1] > temp)
                {
                    arr[j] = arr[j - 1];
                    j--;
                }
                arr[j] = temp;
            }
        }
    }
 
    //希尔排序
    相隔特定增量比较排序，然后再选择更小的增量分割成多个子序列排序
    
    //快速排序
    通过一趟排序将要排序的数据分割成独立的两部分，其中一部分的所有数据都比另外一部分的所有数据都要小，然后再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行，以此达到整个数据变成有序序列。

    快速排序是找出一个元素（理论上可以随便找一个）作为基准(pivot),然后对数组进行分区操作,使基准左边元素的值都不大于基准值,基准右边的元素值 都不小于基准值，如此作为基准的元素调整到排序后的正确位置
}


#pragma mark - 41. swift
    
{

    1. optionals 可选类型  Int?
    
        这个惊叹号表 示“我知道这个可选有值,请使用它。”这被称为可选值的强制解析(forced unwrapping):
        if convertedNumber != nil {
            print("convertedNumber has an integer value of \(convertedNumber!).")
        }
        // 输出 "convertedNumber has an integer value of 123."
    
    可选类型 （optional） Int） 这个值要么是int，要么什么都没有
    nil不能用于非可选的常量或变量
    
    //在 Objective-C 中, nil 是一个指向不存在对象的指 针。在 Swift 中, nil 不是指针——它是一个确定的值,用来表示值缺失。任何类型的可选状态都可以被设置 为 nil ,不只是对象类型。
    
    当你确定可选类型确实包含值之后,你可以在可选的名字后面加一个感叹号( ! )来获取值。这个惊叹号表 示“我知道这个可选有值,请使用它。”这被称为可选值的强制解析(forced unwrapping)
    
    /**
     * 2.
     */
    隐式解析可选类型(implicitly unwrapped optionals)
    想要用作可选的类型 的后面的问号( String? )改成感叹号( String! )来声明一个隐式解析可选类型。
    
    //一个隐式解析可选类型其实就是一个普通的可选类型,但是可以被当做非可选类型来使用,并不需要每次都使用 解析来获取可选值
    let possibleString: String? = "An optional string."
    let forcedString: String = possibleString! // 需要惊叹号来获取值
    let assumedString: String! = "An implicitly unwrapped optional string."
    let implicitString: String = assumedString // 不需要感叹号
    
    
    
    2.函数类型
    var mathFunction: (Int, Int) -> Int = addTwoInts
    
    “定义一个叫做 mathFunction   的变量,类型是‘一个有两个 ￼int 型的参数并返回一个 int 型的值的函 函数”
    数’,并让这个新变量指向 addTwoInts
    
    func addTwoInts(a: Int, _ b: Int) -> Int {
        return a + b
    }
    print("Result: \(mathFunction(2, 3))")
    // prints "Result: 5"
    //就是说，这个类型是mathfunction的函数addtwoints
    
    //函数类型 作为参数，调用的时候，传入这个类型的函数
    func printMathResult(mathFunction: (Int, Int) -> Int, _ a: Int, _ b: Int) {
        print("Result: \(mathFunction(a, b))")
    }
    printMathResult(addTwoInts, 3, 5)
    // prints "Result: 8"
}
    
#pragma mark - 42. sqlite3数据库  sql
{
    //创建表
        create table 表名（字段名1 字段类型1, 字段名2 字段类型2, …）；
        create table if not exists 表名 (字段名1 字段类型1, 字段名2 字段类型2, …) ;
    
    
    
    示例
    
        create table t_student (id integer, name text, age integer, score real) ;
        drop table t_student ;//删除表
        insert into t_student (name, age) values (‘mj’, 10) ; //插入数据   数据库中的字符串内容应该用单引号 ’ 括住
        update t_student set name = ‘jack’, age = 20 ; //更新
    
       // 将t_student表中年龄大于10 并且 姓名不等于jack的记录，年龄都改为 5
        update t_student set age = 5 where age > 10 and name != ‘jack’ ;
        //删除t_student表中年龄小于等于10 或者 年龄大于30的记录
        delete from t_student where age <= 10 or age > 30;
    
    //查询
        select * from t_student where age > 10 ;  //  条件查询
    //别名
        select s.name, s.age from t_student s ;
        给t_student表起个别名叫做s，利用s来引用表中的字段
    //排序
        select * from t_student order by age desc ;  //降序
        select * from t_student order by age asc ;   // 升序默认）
    //只查询。。分页
        select * from t_student limit 4, 8 ;
        可以理解为：跳过最前面4条语句，然后取8条记录
    
    //主键
        create table t_student (id integer primary key, name text, age integer) ;

    //表连接查询
        select s.name,s.age from t_student s, t_class c where s.class_id = c.id and c.name = ‘0316iOS’;

    
    //like 关键字   模糊查找
    NSString *NSsql=[NSString stringWithFormat:@"SELECT id,name,age FROM t_person WHERE name like '%%%@%%' ORDER BY age ASC;",condition];

    // http://www.cnblogs.com/wendingding/p/3871792.html 常用函数

   //  http://www.cnblogs.com/wendingding/p/3871848.html  FMDB 第三方框架操作数据库
    
}


#pragma mark - 43. 地图 CoreLocation(定位) Mapkit(显示)
    
{
    1.CLLocationManager
         // http://www.cnblogs.com/wendingding/p/3901230.html
    CLLocationCoordinate2D  //经纬度
    
    //1.创建位置管理器（定位用户的位置）
    self.locMgr=[[CLLocationManager alloc]init];
    //2.设置代理
    self.locMgr.delegate=self;
    //开始定位用户的位置
    [self.locMgr startUpdatingLocation];

    
    //当定位到用户的位置时，就会调用（调用的频率比较频繁）
     //*/
     -(void)locationManager:(CLLocationManager *)manager didUpdateLocations:(NSArray *)locations
    
    //停止更新位置（如果定位服务不需要实时更新的话，那么应该停止位置的更新）
      [self.locMgr stopUpdatingLocation];
    
    2.CLGeocoder //地理编码
    1）地理编码方法
    　　- (void)geocodeAddressString:(NSString *)addressString completionHandler:(CLGeocodeCompletionHandler)completionHandler;
    （2）反地理编码方法
    　　- (void)reverseGeocodeLocation:(CLLocation *)location completionHandler:(CLGeocodeCompletionHandler)completionHandler;
    
    
    3.MapKit
        _mapView=[[MKMapView alloc]initWithFrame:rect];
        [self.view addSubview:_mapView];
        //设置代理
        _mapView.delegate=self;
    MKAnnotation //大头针
    MKAnnotationView //大头针弹出视图
}


#pragma mark - 44. 通知中心 NSNotificationCenter

{
 
     // http://www.cnblogs.com/kenshincui/p/4168532.html 推送
    // http://blog.csdn.net/niepeng109/article/details/7878146
    1.本地通知
    UILocalNotification
    
    优势：
    
    1.不需要编写多少代码，实现比较简单；
    2.对于一个发出的通知，多个对象能够做出反应，即1对多的方式实现简单
    3.controller能够传递context对象（dictionary），context对象携带了关于发送通知的自定义的信息

    缺点：
    1.在编译期不会检查通知是否能够被观察者正确的处理；
    2.在释放注册的对象时，需要在通知中心取消注册；
    3.在调试的时候应用的工作以及控制过程难跟踪；
    4.需要第三方对喜爱那个来管理controller与观察者对象之间的联系；
    5.controller和观察者需要提前知道通知名称、UserInfo dictionary keys。如果这些没有在工作区间定义，那么会出现不同步的情况；
    6.通知发出后，controller不能从观察者获得任何的反馈信息。
    
    
    1、.注册通知：addObserver:selector:name:object，并实现触发通知后要实现的操作
    [[NSNotificationCenter defaultCenter]addObserver:selfselector:@selector(reloadJpushData:)name:@"JPUSHNOTIFICATION"object:nil];
    - (void)reloadJpushData: (NSNotification *)sender{
        [self getData];
    }
    
    2、发送通知：postNotificationName:object(就在触发通知的方法里写)
    [[NSNotificationCenterdefaultCenter]postNotificationName:@"JPUSHNOTIFICATION"object:nil];
    
    3、移除通知：removeObserver:和removeObserver:name:object:
    移除单个通知:[[NSNotificationCenter defaultCenter] removeObserver:self name:@"JPUSHNOTIFICATION" object:self];
    移除当前所有通知:[[NSNotificationCenterdefaultCenter]removeObserver:self];
    
}
    
#pragma mark - 45. 遍历数组 for in
    
{
    //for in
    NSArray *arr = @[@1,@2,@3,@4,@5];
    for (id objc in arr) {
        NSLog(@"arr == %@", objc);
    }
    //倒序遍历
    for (id objc in [arr reverseObjectEnumerator]) {
        NSLog(@"arr2 == %@", objc);
    }

    //GCD 遍历
    //GCD开启多条线程遍历，适合数组、字典，耗时较长、迭代次数较多的情况
    dispatch_queue_t queue = dispatch_get_global_queue(0, 0);
    dispatch_apply(arr.count, queue, ^(size_t index) {
        NSLog(@"%@ --- %@", arr[index], [NSThread currentThread]);
    });
}
    
#pragma mark - 46. KVC KVO
{

    key valued coding //键值编码   通过键值间接编码
    KVO，即key valued observer 键值观察。监听某一个模型的属性，只要模型属性的值一变化就通知你
    
    //valueforkey  和 valueforkeypath
    [p2  valueForKeyPath:@"name"]
    [persons valueForKeyPath:@"book.bookname"]
    
    //setvalueforkey
    - (id)valueForKey:(NSString *)key;
    - (void)setValue:(id)value forKey:(NSString *)key;
    
    
    2. KVO
    1.注册需要观察的对象的属性addObserver:forKeyPath:options:context:
    2.实现observeValueForKeyPath:ofObject:change:context:方法，这个方法当观察的属性变化时会自动调用
    3.取消注册观察removeObserver:forKeyPath:context:
    
    testPerson = [[myPerson alloc] init];
    [testPerson addObserver:self forKeyPath:@"height" options:NSKeyValueObservingOptionNew context:nil]; //注册
    
    - (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context  //实现方法
    {
        if ([keyPath isEqualToString:@"height"]) {
            NSLog(@"Height is changed! new=%@", [change valueForKey:NSKeyValueChangeNewKey]);
        } else {
            [super observeValueForKeyPath:keyPath ofObject:object change:change context:context];
        }
    }
    
    //取消注册
    - (void)dealloc
    {
        [testPerson removeObserver:self forKeyPath:@"height" context:nil];
        [super dealloc];
    }
    /* 需要用kvc修改属性 */
    KVO的回调要被调用，属性必须是通过KVC的方法来修改的，如果是调用类的其他方法来修改属性，这个观察者是不会得到通知的。
    
   //  kvo 优缺点
    前面两种模式 （即delegate 和通知中心 ）更加适合一个controller与任何其他的对象进行通信，而KVO更加适合任何类型的对象侦听另外一个任意对象的改变（这里也可以是controller，但一般不是controller）。这是一个对象与另外一个对象保持同步的一种方法，即当另外一种对象的状态发生改变时，观察对象马上作出反应。它只能用来对属性作出反应，而不会用来对方法或者动作作出反应。
    
    优点：
    
    1.能够提供一种简单的方法实现两个对象间的同步。例如：model和view之间同步；
    
    2.能够对非我们创建的对象，即内部对象的状态改变作出响应，而且不需要改变内部对象（SKD对象）的实现；
    
    3.能够提供观察的属性的最新值以及先前值；
    
    4.用key paths来观察属性，因此也可以观察嵌套对象；
    
    5.完成了对观察对象的抽象，因为不需要额外的代码来允许观察值能够被观察
    
    缺点：
    
    1.我们观察的属性必须使用strings来定义。因此在编译器不会出现警告以及检查；
    
    2.对属性重构将导致我们的观察代码不再可用；
    
    3.复杂的“IF”语句要求对象正在观察多个值http://www.pudncom.com/ 。这是因为所有的观察代码通过一个方法来指向；
    
    4.当释放观察者时不需要移除观察者。
}


#pragma mark - 47. Core Animation 核心动画

/**
 *  说明
 */
    Core Animation 是作用在CALayer 上的跨 MAC OS 和 iOS 动画处理API,动画执行过程都是在后台操作的，不会阻塞主线程.
    
    addAnimation:forKey:   removeAnimationForKey:
    
    1.CABasicAnimation       --  基本动画
    
    2.CAKeyframeAnimation    --  关键帧动画
        CABasicAnimation只能从一个数值（fromValue）变到另一个数值（toValue），而CAKeyframeAnimation会使用一个NSArray保存这些数值
    
    3.CAAnimationGroup       --  动画组
    
    4.CATransition           --  转场动画
    
    5.CALayer
        a.CAShapeLayer：     形状图层  描述路径，画线，图
        b.CAGradientLayer：  渐变图层
    
    
    
    /**
     *  1.CABasicAnimation       --  基本动画
     */ // http://www.jianshu.com/p/02c341c748f9
    
    a.使用方法animationWithKeyPath:对 CABasicAnimation进行实例化，并指定Layer的属性作为关键路径进行注册。
    
    CABasicAnimation *transformAnima = [CABasicAnimation animationWithkeyPath:@"transform.rotation.y"];
    //防止动画结束后回到初始状态
    transformAnima.removedOnCompletion = NO;
    transformAnima.fillMode = KCAFillModeForwards;
    
    当添加layer动画时，真正移动的并不是视图本身，而是 presentation layer的一个缓存，动画开始时，presentation layer移动，原始layer隐藏，结束时，presentation layer 移除，原始layer显示
    [self.view.layer addAinmation:transformAnima forkey:@"Animation"];
    
    //变化属性  animationWithKeyPath值
    transform.rotation.x        //围绕x轴旋转
    cornerRadius                //圆角
    backgroundColor             //背景色
    bounds                      //大小
    position                    //位置
    contents                    //内容 ex:images
    
    
    
    /**
    *  2.CAKeyframeAnimation       --  关键帧动画
    */ //
    
    关键帧动画是多个values变化。
    
    - values:   属性指明整个动画过程中的关键帧点
    - path:     可以设置一个CGPathRef\CGMutablePathRef,让层跟着路径移动。path只对CALayer的anchorPoint和position起作用。如果你设置了path，那么values将被忽略
    - ketTimes: 设置每个关键帧的时长，首尾必须是0和1
    
    /**
     *  3.CAAnimationGroup       --  动画组
     */ //
    多个CABasicAnimation 动画 加入 group 中
    
    
    
    /**
     *   4.CATransition           --  转场动画
     */ //
    
    a. view 自带转场动画
    + (void)transitionWithView:(UIView*)view duration:(NSTimeInterval)duration options:(UIViewAnimationOptions)options
                                animations:(void(^)(void))animations
                                completion:(void(^)(BOOLfinished))completion;
    
   b. CATransition
    
        CATransition *anim = [CATransition animation];
        anim.type = @"pageCurl";
        anim.duration = 3;
        [view.layer addAnimation:anim forkey nil];
    
    
    /**
     *  5.CAShapeLayer：     形状图层  描述路径，画线，图CAGradientLayer
     */ //      http://www.jianshu.com/p/c5cbb5e05075
    
    CAShapeLayer,UIBezierPath,实现弧形等画图，
    CABasicAnimation          实现动画
    //圆形进度条
    //圆，layer
    CAShapeLayer *shapeLayer = [CAShapeLayer layer];
    shapeLayer.frame = _demoview.bunds;
    //圆， 线
    UIBezierPath *path = [UIBezierPath bezierPathWithOvalInRect:_demoview.bounds];
    
    shapeLayer.path = path.CGPath;
//    shapeLayer.fillColor =
    [_demoview.layer addSublayer:shapeLayer];
    
    //动画
    CABasicAnimation *pathAnima = [CABasicAnimation animationWithKeyPath:@"storkeEnd"];
    pathAnima.fromValue = [NSNumber numberWithFloat:.0f];
    pathAnima.toValue = [NSNumber numberWithFloat:1.0f];
    pathAnima.removedOnCompletion = NO;
    
    [shapeLayer addAnimation:pathAnima forKey:@"strokeEndAnimation"];
    
    
    
    /**
     *  6.CAGradientLayer：     渐变
     */ //
    
    CALayer 的坐标，左上 (0,0) 右下(1,1)
    
    self.gradientLayer = [CAGradientLayer layer];
    self.gradientLayer.frame = CGRectMake(0, 0, 200, 200);
    [self.view.layer addSublayer:self.gradientLayer];
    self.gradientLayer.colors = @[(__bridge id)[UIColor redColor].CGColor,
                                  (__bridge id)[UIColor greenColor].CGColor,
                                  (__bridge id)[UIColor blueColor].CGColor];
    
    //设置颜色渐变方向 (0,0)->(1,1)则45度方向 (0,0)->(1,0)上->下
    self.gradientLayer.startPoint = CGPointMake(0, 0);
    self.gradientLayer.endPoint = CGPointMake(0, 1);
    
    //设置颜色分割点
    self.gradientLayer.locations = @[@(0.25),@(0.5),@(0.75)];
    
  
    
#pragma mark - 48. 内存管理

{
    // 内存管理
    // http://www.cocoachina.com/ios/20160219/15330.html
    
arc:自动引用计数
    对象被持有时计数加一，不被持有时减一，为0时释放
    属性特征
    属性内存管理特征/arc属性：__strong __weak __unsafe_unretained __autoreleasing
    
    __strong:声明引用时不加修饰符，默认强引用，只有当没有任何一个强引用指向时，需要将强引用置nil，持有对象的所有权
    __weak:弱引用不影响对象的释放，对象在被释放的同时，它的弱引用会自动被置nil，一般用在防止循环引用时修饰，不持有所有权
    __autoreleasing:自动释放对象的引用，
    __unsafe_unretained:相当于assign，将引用指向对象，rc为0时，不置nil
    

auroreleasepool:
    @autoreleasepool {
        // 当临时对象不在使用了，它也是会被存放在自动释放池中，而不是直接被释放，等待系统回收；自动释放池，要等到线程执行下一次事件循环时才清空。例如for循环中的临时变量，要等到for循环结束后才会真正被释放
    }
    每一个自动释放池，都是由一系列的autoreleasePoolPage组成的，autoreleasePoolPage大小为4096字节，（双向列表），当对象调用autorelease方法时，会将对象加入autoreleasepoolpage的栈中
    
}
    

#pragma mark - 49. cell性能优化
    
    //面试常用
    {
        1.重用机制
        2.设定cell高度，self.tableView.rowHeight = 88;
        3.减少视图数目
        4.不动态加载视图
        5.异步加载图片，单个cell图片过多或者请求时间过长时，可以在tableview停止滑动之后加载，用scrollviewDidEndDragging和 scrollviewDidEndDecelerating获知停止滑动
        6.减少透明层，当设置为透明时，需要混合每一层的颜色计算得到最终的颜色。不透明时，只取最上面的层的颜色。
        7.阴影设置路径。iOS会先绘制阴影，然后绘制目标本身，这是要通过递归每个字层，计算阴影的路径。
    }
    
    //delegate kvc 通知
    {
        1.delegate:语法清晰，效率高
                    一对一；代码较多
            @protocol testdelegate <nsobject>
            - (void)test;
            @end
        2.NSNotification:代码简单，一对多
                        需要取消注册；太多的话难以维护
        [[nsnotification defaultcenter] addobserer:self selecton@() name:@"enevt1" object:nil];
        3.KVO:观察对象的属性，不是控制器之间的
                观察者必须用strings定义
        
    }
    
    //设计模式
    {
        1.代理
        2.观察者   通知 和 kvo
        3.MVC    层次清晰，易于维护
        4.单例    某个类只有一份实例
        5.MVVM   mvc的增强版,mvc是view/model/vc，mvvm是model/view/viewmodel
                viewmodel中是view和model的逻辑业务层，vc中不再处理数据的逻辑获取，都是放到viewmodel中
    }
    // 分类 扩展
    {
        1.分类 category：不修改原类，扩展方法，不能添加成员变量
            @interface UIView (category)
            -(void)test;
            @end
        
        2.扩展 extension：可以添加成员变量，特例分类；扩展中方法是一定要实现的
    }
    
    
   
#pragma mark - 50. NSURLSession
    
    {
        1.NSURLSessionDataTask
            一般的网络请求，get|post
            支持后台下载；全局session可统一配置；下载多线程异步
        
        // 创建请求路径
        NSURL *url = @"hhtps://...";
        // 创建请求对象
        NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
        // 修改请求方法、请求体、请求头
        request.HTTPMethod = @"POST";
        request.HTTPBody = [@"username=520&pwd=520&type=JSON" dataUsingEncoding:NSUTF8StringEncoding];
        // 创建会话层
        NSURLSession *session = [NSURLSession sharedSession];
        // 创建请求 Task
        NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:requestM completionHandler:
                                          ^(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error) {}
                                          ];
        // 发送请求
        [dataTask resume];

        // 设置代理
        NSURLSession *session = [NSURLSession sessionWithConfiguration:[NSURLSessionConfiguration defaultSessionConfiguration]
                                                              delegate:self delegateQueue:nil];
        
        2.NSURLSessionDownloadTask
            可以断点下载，不能离线下载；
            内部已经实现边接收数据边写入沙盒；
            解决了下载大文件内存飙升的问题
        3. NSURLSessionUploadTask
        
        4. NSURLSessionConfiguation
                defaultSessionConfiguration；默认，持久化存储缓存、cookie证书等。
                ephemeralSessionConfiguration；保存在内存中，当 session 失效或应用终止，所有内容被清空。
                backgroundSessionConfigurationWithIdentifier；
                    在后台上传下载时，应用被终止时，可恢复中断的下载任务
        
    }
    
#pragma mark - 51. Socket 网络编程

#pragma mark - 52. http格式
    
#pragma mark - 53. 第三方原理

#pragma mark - 54. 排序算法
    
#pragma mark - 55. 二叉树、哈希算法
    
#pragma mark - 56. 内存优化、管理

    






    
    
    
    
    
    
    
    
    
    
    
    
    
    

