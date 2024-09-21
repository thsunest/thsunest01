#include<stdio.h>
int main(){
    int A[100];
    int length = sizeof(A) / sizeof(A[0]);
    for (int i = 0;i < 100; i++)
    A[i] = i;
    for (int m = 0; m < length; m++)
    printf("%d,",A[m]);
    

}