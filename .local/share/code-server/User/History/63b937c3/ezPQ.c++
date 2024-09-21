#include<stdio.h>
#include<stdlib.h>
void swap(int &x,int &y){
    int temp;
    temp = x;
    x = y;
    y = temp;
}
void BubbleSort(int A[],int n){
    printf("%d",length);

    for(int i;i < n;i++){
    bool flag = false;
        for(int j = n;j > i;j--){
            if(A[j - 1] > A[j]){
            swap(A[j -1],A[j]);
            flag = true;
            }
            if(!flag)
            return;
        }
    }
}
int main(){
    int Test[] = {124,5,32,623,1};
    int length = sizeof(Test) / sizeof(Test[0]);
    printf("%d",length);
    BubbleSort(Test,length);
    printf("%d",length);

    for(int i;i <length;i++){
        printf("%d,",Test[i]);
    }

    return 0;
}