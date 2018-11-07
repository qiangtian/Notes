//
//  ViewController.m
//  TQSomething
//
//  Created by Jay on 16/1/8.
//  Copyright © 2016年 TQ. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    unsigned int count = 0;
   // Ivar *ivr = class_copyIvarList([ViewController class], &count);
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


//单例测试
- (instancetype)test
{
    static ViewController *service = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        service = [[ViewController alloc]init];
    });
    
    //计算 文字高度
    NSString *text;
    CGSize maxSize; //最大宽度
    CGSize size = [text boundingRectWithSize:maxSize options:(NSStringDrawingUsesLineFragmentOrigin)
                    attributes:@{NSFontAttributeName:[UIFont systemFontOfSize:15]} context:nil].size;
    // 宏 计算文字高度
    #define TX_MULTILINE_TEXTSIZE(text, font, maxSize, mode) [text length] > 0 ? [text \
    boundingRectWithSize:maxSize options:(NSStringDrawingUsesLineFragmentOrigin) \
    attributes:@{NSFontAttributeName:font} context:nil].size : CGSizeZero;

    return service;
}

- (instancetype)test2
{
    static ViewController *service2 = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        service2 = [[ViewController alloc]init];
    });
    return service2;
}
//加载存储在plist
- (NSDictionary *)test2:(NSString *)name
{
    NSString *filename = [NSString stringWithFormat:@"%@.plist",name];
    NSString *filepath = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) [0]  stringByAppendingPathComponent:filename];
    return [[NSDictionary alloc]initWithContentsOfFile:filepath];
}
//存储plist
- (void)saveData:(NSDictionary *)dict withName:(NSString *)name
{
    NSString *fileName = [NSString stringWithFormat:@"%@.plist",name];
    NSString *filepath = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES)[0] stringByAppendingPathComponent:fileName];
    BOOL ret = [dict writeToFile:filepath atomically:YES];
    if (!ret){
        NSLog(@"failed");
    }
}

- (void)test3
{
    NSFileManager *manger = [NSFileManager defaultManager];
    NSString *createdPath = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject];
    NSString *path2 = [NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES)lastObject];
    NSString *path3 = [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES)lastObject];
    
    NSString *path = [NSString stringWithFormat:@"%@/annex", createdPath];
    if (![manger fileExistsAtPath:createdPath]) {
        [manger createDirectoryAtPath:path withIntermediateDirectories:YES attributes:nil error:nil];
    }
}
- (void)test4
{
    dispatch_async(dispatch_get_global_queue(0, 0), ^{
        
    });
    dispatch_time_t time = dispatch_time(DISPATCH_TIME_NOW, NSEC_PER_SEC);
    dispatch_after(time, dispatch_get_main_queue(), ^(void) {
        
    });
}
@end
