
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;
//交换
//void swap(int &x,int &y){int t;t = x;x = y;y = t;}

void BubbleSort(int A[],int n){
    for(int i = 0;i < n -1;i++){
        for(int j = 0; j < n - i - 1;j++){
            if(A[j] > A[j + 1]){
                swap(A[j],A[j + 1]);
            }
        }
    }
}
void BubbleLink(LinkList A){//基于链表的冒泡排序
    if(A == NULL || A->next == NULL) return;
    int swapped = 1;
    LNode *p = NULL;
    LNode *q = NULL;
    while(swapped){
        swapped = 0;
        p = A->next;
        while(p->next != q){
            if(p->data > p->next->data){
                //int temp = p->data;
                //p->data = p->next->data;
                //p->next->data = temp;
                swap(p->data,p->next->data);
                swapped = 1;

            }
            p = p->next;
        }
        q = p;
    }
}

int main(){
    int Test[] = {124,5,32,467,28,23,934,12};
    int length = sizeof(Test) / sizeof(Test[0]);
    BubbleSort(Test,length);
    for(int i= 0;i <length;i++){
        printf("%d,",Test[i]);
    }
    cout<< endl;

    return 0;
}