#include<stdio.h>
int main(){

    int A[100];//初始化
    int length = sizeof(A) / sizeof(A[0]);
    //  赋值
    for (int i = 0;i < 100; i++)
    A[i] = i;

    for (i = 0; i < length;i++){
        int min = 0;
        if( A[i] < min){
            min = A[i];
            pos = i;
        }
        

    }

    /* 03
    for(int k = 0;k < length / 2;k++){
        int temp;
        temp = A[k];
        A[k] = A[length - k-1];
        A[length - k-1] = temp;
    }
    */
    //打印
    for (int m = 0; m < length; m++)
    printf("%d,",A[m]);
    

}