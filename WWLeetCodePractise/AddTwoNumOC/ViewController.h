//
//  ViewController.h
//  AddTwoNumOC
//
//  Created by wangyongwang on 2018/10/12.
//  Copyright © 2018年 ITCoderW. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController


@end

@interface AddTwoNum : NSObject

- (NSArray<NSNumber *> *)twoSumWithArray:(NSArray <NSNumber *>*)arr targetNum:(NSInteger)targetNum ;
@end

