//
//  main.c
//  位运算之二进制中1的个数
//
//  Created by 王永旺永旺 on 2016/11/25.
//  Copyright © 2016年 ITCoderW. All rights reserved.
//




/**
 参考的剑指offer

 
 */
#include <stdio.h>

int numberOf1(int n);
int betterNumberOf1(int n);
_Bool judgeIs2Cifang(int n);
int numberOfTransform(int m, int n);

int main(int argc, const char * argv[]) {
    
    int n;
    int countOf1;
    int betterCountOf1;
    _Bool is2Cifang;
    int transformCount;
    int transM,transN;
    
    while (1) {
        printf("请输入一个整数:\t");
        scanf("%d",&n);
        countOf1 = numberOf1(n);
        betterCountOf1 = betterNumberOf1(n);
        is2Cifang = judgeIs2Cifang(n) ? 1 : 0;
        
        

    
        printf("%d\t转换为二进制之后含有1的个数为\t%d\n\n",n,countOf1);
        printf("%d\t转换为二进制之后含有1的个数为\t%d\n\n",n,betterCountOf1);
        if(is2Cifang){
            printf("%d\t是2的整数次方\n\n",n);
        }else{
            printf("%d\t不是2的整数次方\t\n\n",n);
        }
        
        
        printf("输入待相互转化的两个数:\t");
        scanf("%d %d",&transM,&transN);
        transformCount = numberOfTransform(transM, transN);
        printf("%d和%d转化需要的次数是%d\n\n",transM,transN,transformCount);
        
        
        
    }
    
    return 0;
}


/**
 求1的个数

 @param n 所求的数

 @return 传进去的数的二进制形式中1的个数
 */
int numberOf1(int n){
    int count = 0;
    while (n)
    {
        if ((n & 1)){
            count ++;
        }
        n = n >> 1;
        
    }
    return count;
    

}


/**
 求一个数二进制形式中1的个数的更优解

 @param n 传进去的待求的参数

 @return 返回的待求参数的二进制形式中1的个数
 */
int betterNumberOf1(int n){
    
    int count = 0;
    while(n){
        count++;
        //每一次做下列操作都会使得这个待求的数的二进制的形式中少1个1 这样的好处是减少比较的次数
        n = n & (n-1);
    }
    return count;
}


/**
 相关的问题有：
    1.当判断一个数字a是否是2的整数次方的时候
    2.当判断给定的2个数m,n;
    每次改变二进制形式的1个1; 
    m要经过几步转变为n的时候会用到异或;  
    异或的结果 的二进制的形式含有几个1 就需要相应的几步转换为对方。
 
 */


/**
 判断一个数是否是2的整数次方

 @param n 传进去的待求参数

 @return 返回的是布尔类型的是否是2的整数次方
 */
_Bool judgeIs2Cifang(int n){
    
    return (n & (n-1))? 0 : 1;
}



/**
 两个数的二进制的形式相互转换的时候需要改动的次数

 @param p 参数p
 @param q 参数q

 @return 返回p q相互转换所需的次数
 */
int numberOfTransform(int p, int q){
    
    int count = betterNumberOf1(p ^ q);
    return count;
    

    
}


