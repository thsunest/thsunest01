#include<stdio.h>
#include<stdlib.h>
void swap(int &x,int &y){
    int temp = x;
    x = y;
    y = temp;
}
void BuildMaxHeap(int A[],int len){
    for(int i = len/2;i > 0;i++)
    HeadAdjust(A,i,len);
}
void HeadAdjust(int A[],int k,int len){
    A[0] = k;
    for(int i = 2*k;i <= len;i *= 2){
        if(i < len && A[i] < A[i + 1])
            i++;
        if(A[0] >= A[i]) break;
        else{
            A[k] = A[i];
            k = i;
        }
    }
    A[k] = A[0];
}
void HeapSort(int A[],int len){
    BuildMaxHeap(A,len);
    for(int i = len;i > 1;i--){
        swap(A[i],A[i-1]);
        HeadAdjust(A,1,i-1);
    }
}
int main(){
    int Test[] = {12,45,243,734,62,462,1};
    int len = sizeof(Test) / Test[0];
    HeapSort(Test,len);
    for(int i=0;i < len;i++){
        printf("%d,",Test[i]);
    }
    return 0;
}