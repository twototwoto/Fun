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

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        var nums = [2, 7, 11, 15];
        nums = [3, 2, 4, 3];
        Solution.init().twoSum(nums, 6);
        
    }
}

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

