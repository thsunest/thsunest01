#include<stdio.h>
int partition(int A[],int low,int high){
    int pivot = A[low];
    while(low < high){
        while(low < high && A[high] >= pivot)
         --high;//high向左移动
        A[low] = A[high];
        while(low < high && A[low] <= pivot)
        ++low;//low指针向右移动
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}
void QucikSort(){
    
}
int main(){
    return 0;
}