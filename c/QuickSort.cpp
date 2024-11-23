#include<iostream>
#include"LinkListw/LinkList.h"
using namespace std;
/*int partition(int A[],int low,int high){
    int pivot = A[low]; //以第一个元素为枢轴元素
    while(low < high){
        while(low < high && A[high] >= pivot) --high;//指针移动到比枢轴小的元素
        A[low] = A[high];                           //将比枢轴元素小的元素放到最左边
        while(low < high && A[low] <= pivot) low++; //指针移动到比枢轴大的元素
        A[high] = A[low];                           //将比枢轴元素大的元素放到最右边
    }
    A[low] = pivot; //将枢轴元素放到最终位置
    return low;
}
void QucikSort(int A[],int low,int high){
    if(low == high) return;
    int pivot = partition(A,low,high);
    QucikSort(A,low,pivot - 1);
    QucikSort(A,pivot + 1,high);
}
*/
//快速排序只适用于顺序表
void swap(int &a,int &b){int t = a;a = b;b = t;};
void Qsort(int A[],int L,int R){
    if(L >= R) return;
    int mid = A[L];
    int i = L;int j = R;
    while(i < j){
        while(i < j && A[j] >= mid) j--; //记忆AJ
        while(i < j && A[i] <= mid) i++;
        if(i < j) swap(A[i],A[j]);
    }
    A[L] = A[i];// 记忆 ALiimid
    A[i] = mid;
    Qsort(A,L,i - 1);
    Qsort(A,i + 1,R); 
}
int main(){
    int Test [] = {1,45,235,374,23,63,23,534,234,523,23,4};
    int low = 0;
    int high = sizeof(Test) / sizeof(Test[0]);
    // QucikSort(Test,low,high);
    Qsort(Test,low,high);
    for(int i = 0;i < high;i++){
        cout << Test[i] << ",";
        
    }
    printf("\n");
    
    return 0;
}