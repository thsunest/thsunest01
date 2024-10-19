#include<stdio.h>
#include<iostream>
using namespace std;
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
LinkList List_RearInsert(LinkList &L){
    LNode *s;
    int x;
    LNode *p = L->next;
    
    while(p->next != NULL){
        
    }

}