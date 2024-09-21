#include<stdio.h>
#include<stdlib.h>
void InsertSort(int A[],int n){
    int i,j;
    for(i = 2;i <= n;i++)
        if(A[i] < A[i-1]){
            A[0] = A[i]; //哨兵
            for(j = i - 1;A[0] < A[j];--j)
                A[j + 1] = A [j];
            A[j + 1]= A[0];
        }
}
void halfInsertSort(int A[],int n){
    int i,j,low,high,mid;
    for(i = 2;i <= n;i++){
        A[0]    }
}
int main(){
    int Test[10] = {0,12,24,5,6,7,34,2,5,98};
    InsertSort(Test,9);
    for(int i; i < 10;i++){
        printf("%d,",Test[i]);
    }

    return 0;
}