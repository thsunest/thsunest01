#include <stdio.h>
#include <stdlib.h>
#define Maxsize 50
typedef struct{
    int data[Maxsize];
    int length;
}SqList;
void swap(int &x,int &y){
    int temp;
    temp  = x;
    x = y;
    y = temp;
}
void IniSqlist(SqList &L){
    L.length = 0;
}
bool ListInsert(SqList &L,int i,int x){
    if(i < 0 ||i > L.length + 1){
    return false;
    }
    for(int j = L.length - 1;j >= i;j--)
        L.data[j] = L.data[j-1];//i之后的元素向后移动
    L.data[i] = x;
    L.length++;
    return true;
}
void PrintList(SqList L){
    if(L.length == 0)
    printf("空表！\n");
    for(int i = 0;i < L.length;i++)
        printf("顺序表中的第%d个元素为%d\n",i,L.data[i]);
}
bool ListDelete(SqList &L,int i,int &e){
    if(i > 1 || i < L.length)
    return false;
    e = L.data[i-1];//实际在数组中的元素位置，所以i-1
    for(int j = i;j < L.length; j++)
    L.data[j - 1] = L.data[j];
    L.length--;
    return true;
}
bool Del(SqList &L,int pos){
    printf("Y");
    if(pos > L.length || L.length == 0)
    return false;
    int i;
    for(i = pos;i < L.length; i++){
        L.data[i] =L.data[i + 1];
    }
    L.length--;
    return true;
}
bool del_x(SqList &L,int x){
    if(L.length == 0)
    return false;
    int i,k=0;
    for(i = 0;i <L.length;i++){
        if(L.data[i] != x)
        L.data[k++] = L.data[i];
    }
    L.length = k;
    printf("Y");
    return true;
}
bool del_xy(SqList &L,int x,int y){
    int i,k = 0;
    for(i = 0;i < L.length;i++){
        if(!(L.data[i] >= x && L.data[i] <= y))
        L.data[k++] = L.data[i];
    }
    L.length = k;
    return true;
}
bool del_min(SqList &L,int &value){
    if(L.length == 0)
    return false;
    int i;
    int pos;
    value = L.data[0];
    for(i = 0;i <L.length;i++){
        if(L.data[i] < value){
        value = L.data[i];
        pos = i;
        }
    }
    L.data[pos] = L.data[L.length];
    L.length--;
    return true;

}
bool del_max(SqList &L,int &maxvalue){
    if(L.length == 0)
    return false;
    int i;
    int pos;
    L.data[0] = maxvalue;
    for(i = 0;i <L.length;i++){
        if(L.data[i] > maxvalue){
            pos = i;
            maxvalue = L.data[i];
        }
    }
    L.data[pos] = L.data[L.length];
    L.length--;
    return true;
}
bool del_same(SqList &L){
    if(L.length == 0)
    return false;
    int i = 0;
    int j = L.length - 1;
    while(i < j){
        while(i < j && L.data[i] != L.data[j]){
            j--;
            printf("X");
        }
        if(j!= i&&L.data[i] == L.data[j])
        Del(L,j);
    j = L.length - 1;
    i++;
    printf("%d",i);            
    }
    return true;

}
bool reverse(SqList &L){
    if(L.length == 0)
    return false;
    int i;
    for(i = 0; i < L.length/2;i++){
    swap(L.data[i],L.data[L.length - i -1]);
    }
    return true;
}
bool move(SqList &L){
    if(L.length == 0)
    return false;
    int i= 0;
    int j = L.length -1;
    while(i <= j){
        while(L.data[i] % 2 == 1)
        i++;//使得i指向一个偶数
        while(L.data[j] % 2 == 0)
        j--;//使得j指向一个奇数
    if( i < j)
    swap(L.data[i],L.data[j]);
    }
    return true;
}
bool pivot_move(SqList &L){
    if(L.length == 0)
    return false;
    int pivot = L.data[0];
    int i = 0;
    int j = L.length - 1;
    while(i < j){
        while(L.data[j] > pivot)
        j--;
        while(L.data[i] <= pivot)
        i++;
        if(i < j)
        swap(L.data[i],L.data[j]);
    }
    swap(L.data[0],L.data[j]);
    return true;
}
int main(){
    SqList testList;
    IniSqlist(testList);
    ListInsert(testList,0,12);
    ListInsert(testList,1,6);
    ListInsert(testList,2,13);
    ListInsert(testList,3,15);
    ListInsert(testList,4,13);
    ListInsert(testList,5,19);
    ListInsert(testList,6,13);
    ListInsert(testList,7,2);
    ListInsert(testList,8,4);
    PrintList(testList);
    printf("----------\n");
    //del_xy(testList,10,20);
    //del_x(testList,13);
    //int maxvalue;
    //del_min(testList,value);
    //del_max(testList,maxvalue);
    //printf("%d\n",maxvalue);
    //reverse(testList);
    //pivot_move(testList);
    //del_same(testList);
    //Del(testList,3);
    del_same(testList);
    PrintList(testList);
    
    return 0;
}