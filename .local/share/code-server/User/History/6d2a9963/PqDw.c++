#include<stdio.h>
#include<stdlib.h>
void InsertSort(int A[],int n){
    int i,j;
    for(i = 2;i <= n;i++){
        if(A[i] < A[i-1]){
            A[0] = A[i];
            for(j = i - 1;A[0] < A[j];--j){
                A[j + 1] = A [j];
            }
            A[j + 1] = A[0];
        }
    }
}
int main(){
    int Test[10] = {3,2,1};
    InsertSort(Test,sizeof(Test));
    for(int i; i < sizeof(Test);i++){
        printf("%d",Test[i]);
    }

    return 0;
}