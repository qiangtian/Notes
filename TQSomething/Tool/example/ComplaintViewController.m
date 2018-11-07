//
////
////  ComplaintViewController.m
////  TXLaoXiang
////
////  Created by Jay on 16/1/4.
////  Copyright © 2016年 WolfCub. All rights reserved.
////
//
//#import "ComplaintViewController.h"
//#import "ComplaintCell.h"
//#import "PlaceholderTextView.h"
//#import "UIView+SetFrame.h"
//
//#import "LabelData.h"
//
//
//@interface ComplaintViewController ()<ComplaintCellDelegate>
//{
//    NSMutableArray* cellArr;//转换成的标签数组
//    NSDictionary* arrData;
//    NSString* laid;//提交的labid字符串
//    
//    NSMutableArray *cellOpens;//给cell添加标记
//
//}
//@property (nonatomic, strong) PlaceholderTextView* feedBackTextView;
//
//@end
//
//@implementation ComplaintViewController
//
//- (void)viewDidLoad {
//    [super viewDidLoad];
//    self.view.backgroundColor = LX_VC_BackGroundColor;
//    
//    cellArr  = [[NSMutableArray alloc] init];
//    NSString* title;
//    if ([[UserData currentUser] userRole]==USER_ROLE_DRIVER)
//    {
//        title = @"投诉乘客";
//    }else
//    {
//        title = @"投诉车主";
//    }
//    
//    if (self.isCancelIndent) {
//        
//        title = @"取消订单";
//    }
//    
//    [self addNavView];
//    [self.myNavView setTitleName: title leftBtnName:NAV_BACK_ICON rightBtnNames:nil];
//    
//    __block ComplaintViewController* blockSelf = self;
//    [self.myNavView setLeftBtnBlock:^(id sender) {
//        [TX_APP_DELEGATE backFromViewController:blockSelf];
//    }];
//
//}
//
//- (void)didReceiveMemoryWarning {
//    [super didReceiveMemoryWarning];
//}
//
//-(void)onbuttonInCancelIndent:(UIButton*)sender {
//    
//    if (sender.tag == 111) {
//        
//        //取消订单
//        [self sureToCancelThisIndent];
//        
//    }else {
//        
//        //返回
//        [TX_APP_DELEGATE backFromViewController:self];
//    }
//}
//

#warning cell里面的设置
@protocol ComplaintCellDelegate
//- (void)cellReturnLabelid:(NSInteger)indexpath;
@end
//点击行改变图片
//- (void)cellClicked
//{
//    if (self.delegate)
//    {
//        [self.delegate cellReturnLabelid:self.tag];
//    }
//    
//}
//
//-(void)setOpen:(BOOL)open {
//    
//    if (open) {
//        
//        _selectImgView.hidden = NO;
//    }else {
//        _selectImgView.hidden = YES;
//        
//    }
//}



#warning 方法在这里
//cellOpens = [NSMutableArray array];
//for (int i = 0; i < cellArr.count; i ++)
//{
//    [cellOpens addObject:@"0"];
//}
////列表代理
//- (void)cellReturnLabelid:(NSInteger)indexpath {
//
//    NSLog(@"indexpath ===  %ld", (long)indexpath);
//    
//    
//    //点击 当前 打开的 cell  直接 关闭 然后 retun
//    if ([[cellOpens objectAtIndex:indexpath]integerValue]) {
//        
//        [cellOpens replaceObjectAtIndex:indexpath withObject:@"0"];
//        
//        [self.myTableView reloadData];
//        
//        return;
//    }
//    
//    // 点击 按钮之后 遍历 open 数据源 ，改变里面的值 tableview reload 时候 直接 根据数据源 改变 cell 的属性
//    for (int i = 0; i < cellOpens.count; i++) {
//        
//        if (i == indexpath) {
//            
//            [cellOpens replaceObjectAtIndex:i withObject:@"1"];
//            
//        }else {
//            
//            [cellOpens replaceObjectAtIndex:i withObject:@"0"];
//        }
//    }
//    
//    [self.myTableView reloadData];
//}
//
//#pragma mark - tableView  delegate
//
//- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
//{
//    return [ComplaintCell getCellHeight];
//}
//- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
//{
//    return cellArr.count;
//}
//- (UITableViewCell* )tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
//{
//
//    static NSString* cellId = @"cellIdComplaint";
//    ComplaintCell* cell = (ComplaintCell* )[self.myTableView dequeueReusableCellWithIdentifier:cellId];
//    if (!cell){
//        cell = [[ComplaintCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:cellId];
//        cell.tag = indexPath.row;
//        cell.delegate = self;
//    }
//    cell.open = [[cellOpens objectAtIndex:indexPath.row]integerValue];
//    
//    LabelData *data  = [cellArr objectAtIndex:indexPath.row];
//    cell.titleLab.text = data.name;
//    return cell;
//}
//
//
//#pragma mark -- 键盘
//- (void)scrollViewWillBeginDragging:(UIScrollView *)scrollView
//{
//    [self.feedBackTextView resignFirstResponder];
//}
//- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
//{
//    [self.feedBackTextView resignFirstResponder];
//}
//- (void)keyboardWillShow:(NSNotification *)notification {
//    NSDictionary* userInfo = notification.userInfo;
//    double duration = [userInfo[UIKeyboardAnimationDurationUserInfoKey] doubleValue];
//    CGRect keyboardF  = [userInfo [UIKeyboardFrameEndUserInfoKey] CGRectValue];
//    if (CGRectGetMaxY(self.feedBackTextView.frame) > keyboardF.origin.y)
//    {
//        [UIView animateWithDuration:duration animations:^{
//            self.view.y =  64 - keyboardF.size.height;
//        }];
//    }
//}
//- (void)keyboardWillHide:(NSNotification *)notification {
//    NSDictionary* userInfo = notification.userInfo;
//    double duration = [userInfo[UIKeyboardAnimationDurationUserInfoKey] doubleValue];
//    [UIView animateWithDuration:duration animations:^{
//        self.view.y = 0;
//    }];
//}
//
//@end
