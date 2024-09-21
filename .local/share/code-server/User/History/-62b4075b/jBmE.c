#include<stdio.h>
#define Maxsize 50
typedef struct{
    int data[Maxsize];
    int front,rear;
}SqQueue;
void InitSqueue(SqQueue &Q){
    Q.rear = Q.front = 0;
}
int main(){
    struct SqQueue Q;
    InitSqueue(Q);
    printf("hello");
    return 0;
}