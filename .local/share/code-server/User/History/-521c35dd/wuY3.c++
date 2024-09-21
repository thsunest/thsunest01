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
    }
}
int main(){
    return 0;
}