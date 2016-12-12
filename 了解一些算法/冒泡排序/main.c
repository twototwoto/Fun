//
//  main.c
//  冒泡排序
//
//  Created by 王永旺永旺 on 2016/12/12.
//  Copyright © 2016年 ITCoderW. All rights reserved.
//




#include <stdio.h>

void swap(int *a,int *b);
int main(int argc, const char * argv[]) {
    
    int a[6] = {1,6,8,1,6,8};
    int length = sizeof(a)/sizeof(a[0]);
    _Bool flag = 1;
    
    for (int i=1; i<length && flag; i++) {
        
        flag = 0;
        for (int j=length-1; j>=i; j--) {
            if (a[j-1]>a[j]) {
                swap(&a[j-1], &a[j]);
                flag = 1;
            }
        }
    }
    
    for (int i = 0; i<length; i++) {
        printf("%d\t",a[i]);
    }
    printf("\n");
    return 0;
}

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}






void test(){

    /*
#include <stdio.h>

void swap(int *a,int *b);
int main(int argc, const char * argv[]) {
    //    int a[6] = {1,2,3,4,5,6};
    //    int a[6] = {6,5,4,3,2,1};
    int a[6] = {1,6,8,1,6,8};
    int length = sizeof(a)/sizeof(a[0]);
    _Bool flag = 1;
//    int temp = 0;
    //        int count = 0;
    
    for (int i=1; i<length && flag; i++) {
        
        flag = 0;
        for (int j=length-1; j>=i; j--) {
            if (a[j-1]>a[j]) {
                swap(&a[j-1], &a[j]);
                flag = 1;
            }
        }
        //                printf("%d",count++);
    }
    
    //        printf("\n");
    for (int i = 0; i<length; i++) {
        printf("%d\t",a[i]);
    }
    printf("\n");
    return 0;
}

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
 */

}
