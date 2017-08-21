//
//  main.cpp
//  LinkStackBasicOperation
//
//  Created by Live on 2017/8/18.
//  Copyright © 2017年 ITCoderW. All rights reserved.
//
//参考书籍：严蔚敏版数据结构 数据结构高分阅读等


#include <iostream>
using namespace std;

#define  maxSize 1000
#define WWStr(str) #str
#define WWLine "-------------"


/**
 链栈结点
 */
typedef struct LinkStackNode{
    LinkStackNode *next;
    int data;
}LinkStackNode;

/*链栈操作*/
void linkStackOperation();
/*初始化链栈*/
void initLinkStack(LinkStackNode *&linkStack);
/*判断栈是否为空*/
int isEmptyLinkStack(LinkStackNode *linkStack);
/*链栈的入栈操作*/
int pushLinkStack(LinkStackNode *linkStack,int x);
/*链栈的出栈操作*/
int popLinkStack(LinkStackNode *linkStack,int &x);

/*打印链栈信息*/
void printLinkStack(LinkStackNode *linkStack);

/*写一些注意信息*/
void notice();

int main(int argc, const char * argv[]) {
    
    //链栈操作
    linkStackOperation();
    
    return 0;
}


#pragma mark - 链栈相关操作
void linkStackOperation(){
    
    cout<<WWLine<<"链栈相关操作"<<WWLine<<endl;
    LinkStackNode *linkStack;
    initLinkStack(linkStack);
    
    pushLinkStack(linkStack,1);
    pushLinkStack(linkStack,2);
    pushLinkStack(linkStack,3);
    
    printLinkStack(linkStack);
    
    pushLinkStack(linkStack,4);
    
    isEmptyLinkStack(linkStack);
    printLinkStack(linkStack);
    
    int linkStackTopElement = 0;
    
    popLinkStack(linkStack,linkStackTopElement);
    printLinkStack(linkStack);
    popLinkStack(linkStack,linkStackTopElement);
    printLinkStack(linkStack);
    popLinkStack(linkStack,linkStackTopElement);
    printLinkStack(linkStack);
    
    linkStackTopElement = 10;
    pushLinkStack(linkStack,linkStackTopElement);
    printLinkStack(linkStack);
    popLinkStack(linkStack, linkStackTopElement);
    popLinkStack(linkStack, linkStackTopElement);
    popLinkStack(linkStack, linkStackTopElement);
    printLinkStack(linkStack);
    pushLinkStack(linkStack,20);
    printLinkStack(linkStack);
    
}


#pragma mark - 初始化链栈
void initLinkStack(LinkStackNode *&linkStack){
    
    linkStack = (LinkStackNode *)malloc(sizeof(LinkStackNode));
    linkStack->next = NULL;
}

#pragma mark - 判断链栈是否为空

int isEmptyLinkStack(LinkStackNode *linkStack){
    
    if(linkStack->next == NULL){
        cout<<"链栈为空"<<endl;
        return 1;
    }else{
        cout<<"链栈不为空"<<endl;
        return 0;
    }
}

#pragma mark - 打印链栈信息
void printLinkStack(LinkStackNode *linkStack){
    
    cout<<WWLine<<WWStr(打印链栈的信息:地址)<<linkStack<<WWLine<<endl;
    if(linkStack->next == NULL){
        cout<<"栈为空";
        return;
    }else{
        
        LinkStackNode *p;
        p = linkStack->next;
        //注意下边的代码不能有否则的话就会是直接取出来当前的结点的值后就断了 应该让结点指到链栈 这样的话 才能把后边的值都打印出来
        //        p->next = NULL;
        while(p != NULL){
            
            cout<<p->data<<endl;
            p = p -> next;
            /*栈后进先出 如果是进栈2 3 那么打印栈的信息会是3 2
             *输出链栈信息的地方 感觉链栈的操作就类似于一个链表的头插法
             * */
            
        }
    }
    
}

#pragma mark - 链栈的入栈操作
//注意链栈用的不是引用参数 之前自己用的引用参数不知道是不是造成栈达不到预期的原因 好像不是加不加引用参数的问题 刚刚的问题出在了 打印栈的方法的设置去除了p的结点的next置为NULL
int pushLinkStack(LinkStackNode *linkStack,int x){
    //链栈一般认为不存在栈满的情况
    LinkStackNode *p;
    p = (LinkStackNode *)malloc(sizeof(LinkStackNode));
    
    p->next = NULL;
    p->data = x;
    
    p->next = linkStack->next;
    linkStack->next = p;
    cout<<"刚刚入链栈"<<linkStack<<"的是:"<<x<<endl;
    return 1;
    
}

#pragma mark - 链栈的出栈操作
int popLinkStack(LinkStackNode *linkStack,int &x){
    
    cout<<WWLine<<"出栈操作"<<WWLine<<WWLine<<endl;
    if(linkStack->next == NULL){
        cout<<"栈为空 不能出栈 链栈linkStack:地址"<<linkStack<<endl;
        return 0;
    }else{
        LinkStackNode *p;
        p = linkStack->next;
        x = p->data;
        linkStack->next = p->next;
        free(p);
        cout<<"链栈linkStack:地址"<<linkStack<<"当前出栈元素"<<x<<endl;
        return 1;
    }
    
}


#pragma mark - 注意事项
void notices(){
    /***
     * 入栈 出栈要有引用参数指向栈 才能够真的改变栈的值
     * 出栈还要有引用参数指向出栈的元素 以记录下来刚刚出栈的元素
     */
    
    /*栈后进先出 如果是进栈2 3 那么打印栈的信息会是3 2
     *输出链栈信息的地方 感觉链栈的操作就类似于一个链表的头插法
     * */
}



