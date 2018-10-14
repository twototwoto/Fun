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
    [[AddTwoNum new] twoSumWithArray:arr targetNum:6];
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
/**
 
 class Solution {
 func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
 
 for index in 0..<nums.count {
 for second in (index+1)..<nums.count {
 print(index, second);
 if (nums[index] + nums[second] == target) {
 print([index, second])
 return [index, second]
 }
 }
 }
 return [0, 0];
 }
 }
 
 */
@end
