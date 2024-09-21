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
int main(){
    SqQueue Q;
    InitSqueue(Q);
    isEmpty(Q);
    bool F = isEmpty(Q);
    printf("%d",F);
    return 0;
}