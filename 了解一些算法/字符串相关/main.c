//
//  main.c
//  字符串相关
//
//  Created by 王永旺永旺 on 2016/11/26.
//  Copyright © 2016年 ITCoderW. All rights reserved.
//参考书籍：编程之法

#include <stdio.h>
char* leftRotateString(char *s, int n, int m);
int main(int argc, const char * argv[]) {
    
    char s[] = "abcde";
    printf("旋转2位字符串位为%s\n",leftRotateString(s, 5, 2));
    return 0;
    
}


/**
 字符串的蛮力旋转  较优的方法下次更新
 
 @param s 字符串
 @param n  字符串的长度
 */
void leftShiftOne(char *s, int n){
    
    //保存第一个字符串
    char t = s[0];
    for (int i = 1; i < n; i++) {
        //往前挪
        s[i-1] = s[i];
    }
    // "最后一位" 赋值为 "第一位" 的值
    s[n-1] = t;
    
}


/**
 把长度为n的字符串的 m 位进行旋转操作
 
 @param s 字符串s
 @param n 字符串s的长度
 @param m 字符串s要旋转的位数
 
 @return 返回旋转的结果
 */
char* leftRotateString(char *s, int n, int m){
    while(m--){
        leftShiftOne(s, n);
    }
    return s;
}

void others(){

    //    char *resultStr;
    //    for (int m = 1; m<=5 ; m++) {
    //    resultStr = leftRotateString(s, 5, 3);
    //    resultStr = leftRotateString(s, 5, 1);
    //    printf("旋转字符串%s-%d位为%s\n",s,m,resultStr);
    //    printf("%lu-%lu",sizeof(s),sizeof(s[0]));
    //    }

}
