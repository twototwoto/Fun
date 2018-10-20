//
//  ViewController.m
//  AddTwoNumOC
//
//  Created by wangyongwang on 2018/10/12.
//  Copyright © 2018年 ITCoderW. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    NSArray *arr = @[@(3), @(2), @(4)];
    NSInteger target = 6;
    [[AddTwoNum new] twoSumWithArray:arr targetNum:6];
    
    NSMutableDictionary *dictM = [NSMutableDictionary dictionary];
    for (NSInteger i = 0; i < arr.count; i++) {
        [dictM setObject:@(i) forKey:arr[i]];
    }
    
    for (NSInteger i = 0; i < arr.count; i++) {
        NSNumber *matchValue = @(target - [arr[i] integerValue]);
        if ([[dictM objectForKey:matchValue]integerValue] != i) {
            NSLog(@"%@", @[@(i), [dictM objectForKey:matchValue]]);
        }
    }
}


@end


@implementation AddTwoNum

- (NSArray<NSNumber *> *)twoSumWithArray:(NSArray <NSNumber *>*)arr targetNum:(NSInteger)targetNum {
    
    for (NSInteger firstIndex = 0; firstIndex < arr.count - 1; firstIndex++) {
        for (NSInteger secondIndex = firstIndex + 1; secondIndex < arr.count; secondIndex ++) {
            if ([arr[firstIndex]integerValue] + [arr[secondIndex]integerValue] == targetNum)  {
                NSLog(@"%@",@[@(firstIndex), @(secondIndex)]);
                return @[@(firstIndex), @(secondIndex)];
            }
        }
    }
    return @[];
}

@end
