//
//  main.cpp
//  WWSequenceQueueBasic
//
//  Created by Live on 2017/8/21.
//  Copyright © 2017年 ITCoderW. All rights reserved.
//
//参考书籍：严蔚敏版数据结构 数据结构高分阅读等
//参考文章：http://www.cnblogs.com/newwy/archive/2010/10/10/1847461.html

#include <iostream>
using namespace std;

#define  maxSize 1000
#define WWStr(str) #str
#define WWLine "-------------"

/**
 顺序队列结点
 */
typedef struct SequenceQueueNode{
    int data[maxSize];
    int front,rear;
}SequenceQueueNode;


/**
 顺序队列的操作
 */
void sequenceQueueOperation();
/**
 初始化顺序队列的操作
 */
void initSequenceQueue(SequenceQueueNode &sequenceQueue);


/**
 判断顺序队列是否为空

 @param sequenceQueue 队列
 @return 是否为空
 */
int isSequenceQueueEmpty(SequenceQueueNode sequenceQueue);


/**
 入顺序队列

 @param sequenceQueue 入的顺序队列
 @param x 入队列的元素
 @return 入队列成功与否
 */
int enSequenceQueueWithDataX(SequenceQueueNode &sequenceQueue,int x);

/**
 顺序队列之元素出队列

 @param sequenceQueue 出队的度列
 @param x 当前出队列的元素
 @return 返回的是出队列成功与否
 */
int outSequenceQueueWithDataX(SequenceQueueNode &sequenceQueue,int &x);

#pragma mark - 打印队列信息

/**
 打印顺序队列中的元素

 @param sequenceQueue 待打印顺序队列
 @param length 顺便获取顺序队列的长度
 @return 返回顺序队列的长度
 */
int printSequenceQueue(SequenceQueueNode sequenceQueue,int &length);
int main(int argc, const char * argv[]) {
    
    sequenceQueueOperation();
    return 0;
}

#pragma mark - 顺序队列相关操作
void sequenceQueueOperation(){
    
    SequenceQueueNode sequenceQueue;
    
    initSequenceQueue(sequenceQueue);
    
    isSequenceQueueEmpty(sequenceQueue);
    
    enSequenceQueueWithDataX(sequenceQueue, 1);
    enSequenceQueueWithDataX(sequenceQueue, 2);
    enSequenceQueueWithDataX(sequenceQueue, 3);
    int length = 0;
    printSequenceQueue(sequenceQueue, length);
    cout<<"顺序队列当前长度"<<length<<endl;
    
    int currentElement = 0;
    outSequenceQueueWithDataX(sequenceQueue, currentElement);
    outSequenceQueueWithDataX(sequenceQueue, currentElement);
    
    isSequenceQueueEmpty(sequenceQueue);
    
    printSequenceQueue(sequenceQueue, length);
    cout<<"顺序队列当前长度"<<length<<endl;
    outSequenceQueueWithDataX(sequenceQueue, currentElement);
    
    outSequenceQueueWithDataX(sequenceQueue, currentElement);
    printSequenceQueue(sequenceQueue, length);
    cout<<"顺序队列当前长度"<<length<<endl;
    
}

#pragma mark - 初始化队列
void initSequenceQueue(SequenceQueueNode &sequenceQueue){
    sequenceQueue.front = sequenceQueue.rear = 0;
    cout<<WWLine<<WWStr(初始化队列队列地址:)<<&sequenceQueue<<WWLine<<endl;
}

#pragma mark - 判断顺序队列是否为空
int isSequenceQueueEmpty(SequenceQueueNode sequenceQueue){
    cout<<WWLine<<WWStr(判断顺序队列是否为空列队列地址:)<<&sequenceQueue<<((sequenceQueue.front == sequenceQueue.rear)?WWStr(为空):WWStr(不空))<<WWLine<<endl;
    return sequenceQueue.front == sequenceQueue.rear;
}

#pragma mark - 入顺序队列
int enSequenceQueueWithDataX(SequenceQueueNode &sequenceQueue,int x){
   
    if ((sequenceQueue.rear + 1)%maxSize == sequenceQueue.front
        )//队列为满 不能入队列
    {
        cout<<WWStr(队列满了 不能入队)<<endl;
        return 0;
    }
     cout<<WWLine<<WWStr(入顺序队列)<<&sequenceQueue<<WWStr(当前入队元素)<<x<<WWLine<<endl;
    sequenceQueue.rear = (sequenceQueue.rear + 1)% maxSize;
    sequenceQueue.data[sequenceQueue.rear] = x;
    return 1;
    
}

#pragma mark - 顺序队列之元素出队列
int outSequenceQueueWithDataX(SequenceQueueNode &sequenceQueue,int &x){
    if (sequenceQueue.rear == sequenceQueue.front)
    {//队列为空 不能出队列
        cout<<WWStr(队列为空 不能出队列)<<endl;
        return 0;
    }
    sequenceQueue.front = (sequenceQueue.front + 1) % maxSize;
    x = sequenceQueue.data[sequenceQueue.front];
    cout<<WWLine<<WWStr(顺序队列之元素出队列队列地址:)<<&sequenceQueue<<WWStr(当前出队列元素:)<<x<<WWLine<<endl;
    return 1;
}

#pragma mark - 打印队列信息
int printSequenceQueue(SequenceQueueNode sequenceQueue,int &len){
    
    if (isSequenceQueueEmpty(sequenceQueue)) {
        cout<<WWStr(队列为空)<<endl;
        len = 0;
        return 0;
    }
    len = 0;
    cout<<WWLine<<WWStr(打印顺序队列的信息 队列地址:)<<&sequenceQueue<<endl;
    SequenceQueueNode node;
    node = sequenceQueue;
    cout<<WWStr(打印顺序队列中的元素:)<<endl;
    int temp;
    while (outSequenceQueueWithDataX(node, temp)) {
        cout<<WWStr(自己的打印队列的输出在是这行)<<node.data[node.front]<<endl;
        ++ len;
    }
    cout<<WWStr(顺序队列的长度为)<<len<<endl;
    return len;
}



