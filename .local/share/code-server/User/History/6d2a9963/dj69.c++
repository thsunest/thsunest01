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
int main(){
    int Test[10] = {0,9,8,7,6,5,3,2,1};
    InsertSort(Test,9);
    for(int i; i < 10;i++){
        printf("%d",Test[i]);
    }

    return 0;
}