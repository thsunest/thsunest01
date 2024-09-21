#include<stdio.h>
#inlcude<stdlib.h>
void InsertSort(int A[],int n){
    int i,j;
    for(i = 2;i <= n;i++){
        if([i] < [i-1]){
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
    InsertSort(Test,3);

    return 0;
}