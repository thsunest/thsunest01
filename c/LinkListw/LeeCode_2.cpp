#include "LinkList.h"
#include <iostream>
using namespace std;
LinkList add(LinkList &A,LinkList &B){
    LNode *q = A;
    LNode *p = B;
    int length_A = 0;
    int length_B = 0;
    while(q){
        length_A++;
        q = q->next;
    }
    while(p){
        length_B++;
        p = p->next;

    }
    int flag = 0; //进位标志
    if(length_A > length_B){ //处理不等长链表
        q = A;
        p = B;
    }else{
        q = B;
        p = A;
    }
    while(q){
        if(p) q->data += p->data; //按位相加
        if(q->data >= 10){  //逢十进一
        q->data -= 10;
        flag = 1;
        }
        q = q->next; //指针移动处理下一个结点
        if(p) p = p->next;
        if(flag != 0){
            q->data++;
            flag = 0; //本位进位完成
            if(q->data >= 10){ //进位再产生进位
                q->data -= 10;
                flag = 1;       //生成下一位进位标志
            }
        }
        if(p == NULL || flag != 0){
            if(q) q->data++;
            flag = 0;
        }


    }
    return length_A > length_B ? A : B;

}
int main(){
    LNode *node1 = (LNode *)malloc(sizeof(LNode));
    LNode *node2 = (LNode *)malloc(sizeof(LNode));
    LNode *node3 = (LNode *)malloc(sizeof(LNode));
    node1->data = 9;
    node2->data = 9;
    node3->data = 9;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    LNode *A = node1;
    LNode *node4 = (LNode *)malloc(sizeof(LNode));
    LNode *node5 = (LNode *)malloc(sizeof(LNode));
    node4->data = 9;
    node5->data = 9;
    node4->next = node5;
    node5->next =NULL;
    LNode *B = node4;


    LNode *C =(LNode *)malloc(sizeof(LNode));
    C = add(A,B);
    ListPrint(C);
    return 0;
}