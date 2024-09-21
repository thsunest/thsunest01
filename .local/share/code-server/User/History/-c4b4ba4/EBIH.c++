#include<stdio.h>
int Partition(int A[],int low,int high){
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
void QucikSort(int A[],int low,int high){
    if(low < high){
        int pivotpos = Partition(A,low,high);
        QucikSort(A,low,pivotpos - 1);
        QucikSort(A,pivotpos + 1,high);
    }
}
int main(){
    int Test [] = {1,45,235,374,23,634,23,534,234,523,23,4};
    int low = 0;
    int high = sizeof(Test) / sizeof(Test[0]);

    QucikSort(Test,low,high);
    for(int i = 0;i < high;i++){
        printf("%d,",Test[i]);
    }
    return 0;
}