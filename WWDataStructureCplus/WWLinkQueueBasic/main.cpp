//
//  main.cpp
//  WWLinkQueueBasic
//
//  Created by Live on 2017/8/22.
//  Copyright © 2017年 ITCoderW. All rights reserved.
//
//参考书籍：严蔚敏版数据结构 数据结构高分阅读等

#include <iostream>
using namespace std;

#define  maxSize 1000
#define WWStr(str) #str
#define WWLine "-------------"


/**
 链队列结点结构体
 */
typedef struct LinkQueueNode{
    int data;               //数据域
    struct LinkQueueNode *next; //指针域
}LinkQueueNode;


/**
 链队列类型定义(只有一个头尾指针而已)
 */
typedef struct{
    LinkQueueNode *front;    //链队列头指针
    LinkQueueNode *rear;     //链队列尾指针
}LinkQueue;


/**
 链队列相关操作
 */
void linkQueueOperation();
/**
 初始化链队列

 @param linkQueue 链队列linkQueue
 */
void initLinkQueue(LinkQueue *&linkQueue);

/**
 判断链队列是否为空

 @param linkQueue 链队列
 */

/**
 判断链队列是否为空

 @param linkQueue 链队列
 @return 为空返回1 不为空返回0
 */
int isEmptyLinkQueue(LinkQueue *linkQueue);

/**
入队列

 @param linkQueue 链队列
 @param x 要入队列的元素
 */
void enLinkQueue(LinkQueue *linkQueue,int x);
#pragma mark - 出队列

/**
 链队列出队列

 @param linkQu 要出队列的链队列
 @param x 返回出队列的数据域的值
 @return 返回能否出队列
 */
int outLinkQueue(LinkQueue *linkQu,int &x);

int main(int argc, const char * argv[]) {
    linkQueueOperation();
    return 0;
}


#pragma mark - 链队列相关操作
void linkQueueOperation(){

    LinkQueue *linkQueue;
    initLinkQueue(linkQueue);
    isEmptyLinkQueue(linkQueue);
    //1 2 3 依次入队列
    enLinkQueue(linkQueue, 1);
    enLinkQueue(linkQueue, 2);
    enLinkQueue(linkQueue, 3);
    //
    int currentFrontData;
    outLinkQueue(linkQueue, currentFrontData);
    outLinkQueue(linkQueue, currentFrontData);
    outLinkQueue(linkQueue, currentFrontData);
    
    outLinkQueue(linkQueue, currentFrontData);
    
    enLinkQueue(linkQueue, 4);
    outLinkQueue(linkQueue, currentFrontData);
    
    
}

#pragma mark - 初始化链队列
void initLinkQueue(LinkQueue *&linkQueue){
    
    cout<<WWLine<<WWStr(链队列初始化操作地址)<<&linkQueue<<WWLine<<endl;
    //之前一直是笔误导致了下边的这种情况的发生 还找了半天错 所以以后的话最好要注意别把参数名和类型的名字写得太像
    //    linkQueue = (linkQueue *)malloc(sizeof(linkQueue));
    linkQueue = (LinkQueue *)malloc(sizeof(LinkQueue));
    linkQueue->front = NULL;
    linkQueue->rear = linkQueue->front;
    
}

#pragma mark - 判断队列是否为空
int isEmptyLinkQueue(LinkQueue *linkQueue){
    cout<<WWLine<<WWStr(判断链队列是否为空 队列地址)<<&linkQueue<<WWLine<<endl;
    if (linkQueue->front == NULL || linkQueue->rear == NULL) {
        return 1;
    }
    return 0;
}

#pragma mark - 入队列
void enLinkQueue(LinkQueue *linkQueue,int x){
    cout<<WWLine<<WWStr(进入链队列地址)<<linkQueue<<WWLine<<endl;
    
    cout<<WWStr(当前入队列的元素)<<x<<endl;
    LinkQueueNode *Node = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
    Node->data = x;
    Node->next = NULL;
    
    if(isEmptyLinkQueue(linkQueue)){
        //如果入的是空队列 则新结点是队首结点也是队列尾结点
        linkQueue->front = Node;
        linkQueue->rear = linkQueue->front;
    }else{
        //将新结点链到队列尾部 rear指向它
        linkQueue->rear->next = Node;
        linkQueue->rear = Node;
    }
    
}

#pragma mark - 出队列
int outLinkQueue(LinkQueue *linkQu,int &x){
    cout<<WWLine<<WWStr(出队列链队列地址)<<linkQu<<WWLine<<endl;
    
    if (isEmptyLinkQueue(linkQu)) {
        //链队列为空不能够出队列
        cout<<WWStr(链队列为空，不能出队列)<<endl;
        return 0;
    }
    
    //把当前链队列的头的数据赋值给x
    LinkQueueNode *Node = linkQu->front;
    x = Node->data;
    
    cout<<WWStr(当前出队列的元素:)<<x<<endl;
    
    //移动指针 如果有的话 front指向下一个结点
    if(linkQu->front == linkQu->rear){
        linkQu->front = NULL;
        linkQu->rear =NULL;
    }else{
        linkQu->front = linkQu->front->next;
    }
    free(Node);
    return 1;
}


