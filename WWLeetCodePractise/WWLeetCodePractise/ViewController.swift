//
//  ViewController.swift
//  WWLeetCodePractise
//
//  Created by wangyongwang on 2018/10/12.
//  Copyright © 2018年 ITCoderW. All rights reserved.
//
/**
 leetcode 练习
 https://leetcode.com/problems/two-sum/description/
 1.two sum 练习普通解法
 
 Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 
 You may assume that each input would have exactly one solution, and you may not use the same element twice.
 
 Example:
 
 Given nums = [2, 7, 11, 15], target = 9,
 
 Because nums[0] + nums[1] = 2 + 7 = 9,
 return [0, 1].
 
 */

/**
 * 空间换时间
 * 使用字典存放 数组的值 ： 数组索引
 * 遍历数组 过程中 用（target - 当前遍历的值）
 * 使用自定去 根据上边的key 获取数组的索引matchIndex
 * 如果matchIndex 和当前遍历的index 不同
 * 则返回 (matchIndex, index)
 */

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        var nums = [2, 7, 11, 15];
        nums = [3, 2, 4, 3];
        nums = [2, 5, 5, 11];
        let indexArr = Solution.init().twoSum(nums, 10);
        print(indexArr);
    }
}


class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        
        var dictM = [Int: Int]()
        
        for (currentIndex, currentValue) in nums.enumerated() {
            dictM[currentValue] = currentIndex;
        }
        
        for (currentIndex, currentValue) in nums.enumerated() {
            if let matchIndex = dictM[target - currentValue] {
                if matchIndex != currentIndex {
                    print([currentIndex, matchIndex])
                    return [currentIndex, matchIndex]
                }
            }
        }
        return [];
    }
}

/**
class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        
        var dictM = [Int: Int]()
        
        for (index, value) in nums.enumerated() {
            dictM[value] = index;
        }
        
        for (index, value) in nums.enumerated() {
            let match = target - value
            if ((dictM[match] != nil) && dictM[match] != index) {
                print([index, dictM[match]!])
                return [index, dictM[match]!]
            }
        }
        return [];
    }
}

 */

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

