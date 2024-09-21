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
bool EnQueue
int main(){
    SqQueue F;
    InitSqueue(F);
    printf("%d",isEmpty(F));
    return 0;
}