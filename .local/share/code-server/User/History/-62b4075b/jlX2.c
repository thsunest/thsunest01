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
    SqQueue F;
    InitSqueue(F);
    printf("hello");
    return 0;
}