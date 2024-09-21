#include<stdio.h>
int partition(int A[],int low,int high){
    int pivot = A[low];
    while(low < high){
        while(low < high && A[high] >= pivot)
         --high;

    }

}
int main(){
    return 0;
}