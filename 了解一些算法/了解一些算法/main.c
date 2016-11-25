//
//  main.c
//  了解一些算法
//
//  Created by 王永旺永旺 on 2016/11/25.
//  Copyright © 2016年 ITCoderW. All rights reserved.
//


/**
 给定斐波那契数列的项数求对应的数值
 参考：剑指Offer
 */
#include <stdio.h>

int fib(int n);
long long fibonacci(unsigned int n);
int main(int argc, const char * argv[]) {
    
    int n;
    
    while (1) {
        
        printf("请输入你想知道到的斐波那契数列的项数:\t");
        scanf("%d",&n);
        int result = fib(n);
        long long googResult = fibonacci(n);
        printf("与之对应的斐波那契数列数列的值为:\t%d\t%lld\n\n",result,googResult);
        
        
    }
    return 0;
}


int fib(int n){
    
    if(n == 0){
        return 0;
    }else if(n == 1){
        return 1;
    }else {
        return fib(n-1) + fib(n-2);
    }

}

//斐波那契数列数列求解优化

long long fibonacci(unsigned int n){
    
    int result[] = {0,1};
    if (n < 2){
        return result[n];
    }
    long long smallest = 0;
    long long smaller = 1;
    long long temp = 0;
    
    for(int i=2; i<=n; i++){
        
        //0 1 1 2 3 5 8 13 21
        temp = smaller + smallest;
        
        smallest = smaller;
        smaller = temp;
        
    }
    return temp;
    
}


