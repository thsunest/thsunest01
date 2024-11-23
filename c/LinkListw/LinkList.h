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
    cout << endl;
}
LinkList HeadInit(LinkList &L){
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
    return L;
}
LinkList List_RearInsert(LinkList L){
    L = (LNode *)malloc(sizeof(LNode));
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
void Line(){
    cout << "-------------------------" << endl;
}
void TestPrint(LinkList L){
    Line();
    ListPrint(L);
}
//创建结点
LNode* createNode(int data){
    LNode * newNode = (LNode *)malloc(sizeof(LNode));
    newNode->data = data;
    newNode->next = NULL;
    if(!newNode)
    exit(1);
}
//创建带头结点的单链表
LNode * createHead(){
    LNode * head = (LNode *)malloc(sizeof(LNode));
    if(!head){
        exit(1);
    }
    head->data = 0;
    head->next = NULL;
    return head;
}
//后插法
void append(LNode *head,int data){
    int i = data;
    LNode *newNode = createNode(i);
    LNode *current = head;
    while(current->next){
        current = current->next;

    }
    current->next = newNode;
}