#include<stdio.h>
#include<iostream>
namespace std:
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;
void ListPrint(LinkList L){
    LNode *p = L;
    while(p != NULL){
        cout << p->data;
    }
    
}