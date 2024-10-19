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
        cout << p->data << "->";
        p = p->next;
    } 
}
LinkList List_RearInsert(LinkList &L){
    int x;
    LNode *r = L;
    cin >> x;
    while(x != 9999){
        LNode *s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        cin >> x;
    }
    return L;

}