#include<stdio.h>

#define Maxsize 50
typedef struct{
    int data[Maxsize];
    int front,rear;
}SqQueue;
void InitSqueue(SqQueue &Q){
    Q.rear = Q.front = 0;
}
bool isEmpty(SqQueue Q){
    if (Q.rear == Q.front)
    return true;
    else 
    return false;
}
bool EnQueue(SqQueue &Q,int x){
    if((Q.rear + 1) % Maxsize == Q.front)
    return false; //队列已满
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % Maxsize;
    return true;
    }
int main(){
    SqQueue F;
    InitSqueue(F);
    EnQueue(F,1);
    printf("%d",isEmpty(F));
    return 0;
}