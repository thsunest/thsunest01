#include<iostream>
#include<stdio.h>
using namespace std;

#define Maxsize 50
typedef struct{
    int data[Maxsize];
    int front,rear;
}SqQueue;
//队列初始化
void InitSqueue(SqQueue &Q){
    Q.rear = Q.front = 0;
}
//队列判空
bool isEmpty(SqQueue Q){
    if (Q.rear == Q.front)
    return true;
    else 
    return false;
}//入队操作
bool EnQueue(SqQueue &Q,int x){
    if((Q.rear + 1) % Maxsize == Q.front)
        return false; //队列已满
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % Maxsize;
    return true;
    }
//出队操作，指定位置的元素出队
bool DeQueue(SqQueue &Q, int &x){
    if(Q.rear == Q.front)
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % Maxsize;
    return true;
}
int main(){
    int x = 0;
    SqQueue F;
    InitSqueue(F);
    EnQueue(F,1);
    DeQueue(F,x);
    printf("%d%d",isEmpty(F),x);
    cout << isEmpty(F) << endl;
    return 0;

}