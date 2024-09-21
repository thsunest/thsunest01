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

int main(){
    return 0;
}