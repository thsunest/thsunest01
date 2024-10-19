#include<stdio.h>
#include<iostream>
using namespace std;
#define Maxsize 6
typedef struct {
    int data[Maxsize];
    int front,rear;
}SqQueue;
typedef struct LinkNode{
    int data;
    struct LinkNode *next;
}LinkNode;
typedef struct{
    LinkNode *front,*rear;
}LinkQueue;

//初始化队列
void InitQueue(SqQueue &Q){
    Q.rear = Q.front = 0;
}
//队列判空
bool isEmpty(SqQueue Q){
    if(Q.rear == Q.front)
    return true;
    else
    return false;
}
//判断是否满队
bool isFull(SqQueue Q){
    return (Q.rear + 1) % Maxsize == Q.front;
}
//入队
bool EnQueue(SqQueue &Q,int x){
    if(isFull(Q))
    return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % Maxsize;
    return true;
}
//出队
bool DeQueue(SqQueue &Q,int &x){
    if(isEmpty(Q))
    return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % Maxsize;
    return true;
}
//从队头打印输出到队尾
void PrintQueue(SqQueue Q){
    if(isEmpty(Q))
    printf("empty queue!");
    int i = Q.front;
    while( Q.rear != i){
        cout << Q.data[i % Maxsize] << "← ";
        i = (i + 1) % Maxsize;
    }
    cout<< endl;

}