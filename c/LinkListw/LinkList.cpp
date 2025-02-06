#include<iostream>
using namespace std;
#include"LinkList.h"
LNode* Reverse(LinkList L){
    LNode *curr = L->next;
    LNode *pre = NULL;
    LNode *next = NULL;
    while(curr){
        next = curr->next;    //存
        curr->next = pre;     //转向
        pre = curr;           //移动
        curr = next;
    }
    L->next = pre;           //处理头部
    return L;
}
int main(){
    LinkList A = List_RearInsert(A);
    ListPrint(A);
    cout << "----" << endl;
    Reverse(A);
    ListPrint(A);
    return 0;
}
