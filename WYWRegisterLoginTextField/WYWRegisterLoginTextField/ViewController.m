//
//  ViewController.m
//  WYWRegisterLoginTextField
//
//  Created by 王永旺永旺 on 2016/11/25.
//  Copyright © 2016年 ITCoderW. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    CGFloat margin = 20;
    CGFloat width = self.view.bounds.size.width - margin * 2;
    CGFloat height = self.view.bounds.size.height * 0.06;
    CGFloat nameY = margin * 4;
    CGFloat pwdY = margin * 6.8;
    
    UITextField *nameTextField = [[UITextField alloc]initWithFrame:CGRectMake(margin, nameY, width, height)];
    UITextField *passwdTextField = [[UITextField alloc]initWithFrame:CGRectMake(margin, pwdY, width, height)];
    
    nameTextField.placeholder = @"请输入用户名";
    //一键清空TextField
    nameTextField.clearButtonMode = UITextFieldViewModeWhileEditing;
    
    UIImageView *imageViewUser = [[UIImageView alloc]initWithFrame:CGRectMake(0, 0, 30, 20)];
    imageViewUser.image = [UIImage imageNamed:@"Contacts"];
    
    nameTextField.leftView = imageViewUser;
    //开启leftView总是显示的模式
    nameTextField.leftViewMode=UITextFieldViewModeAlways;
    nameTextField.borderStyle = UITextBorderStyleRoundedRect;
    nameTextField.backgroundColor = [UIColor groupTableViewBackgroundColor];
    
    
    passwdTextField.placeholder = @"请输入密码";
    //密码的输入的效果
    passwdTextField.secureTextEntry = YES;
    //一键清空TextField
    passwdTextField.clearButtonMode = UITextFieldViewModeWhileEditing;
    
    UIImageView *imageViewPwd=[[UIImageView alloc]initWithFrame:CGRectMake(0, 0, 30, 20)];
    imageViewPwd.image=[UIImage imageNamed:@"lock"];
    
    passwdTextField.leftView=imageViewPwd;
    //开启leftView总是显示的模式
    passwdTextField.leftViewMode=UITextFieldViewModeAlways;
    passwdTextField.borderStyle = UITextBorderStyleRoundedRect;
    passwdTextField.backgroundColor = [UIColor groupTableViewBackgroundColor];
    
    [self.view addSubview:nameTextField];
    [self.view addSubview:passwdTextField];

}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
