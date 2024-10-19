#include"LinkList.h"
void Intersection(LinkList A,LinkList B,LinkList &C){
    LNode *p = A->next;
    LNode *q = B->next;
    LNode *r = C;
    //扫描A链表
    while(p){
        q = B->next;//重置q指针到B链表开头
        while(q){
            //A链表和B链表结点值相同
            if(p->data == q->data){
                LNode *s = (LNode*)malloc(sizeof(LNode));
                s->data = q->data;
                s->next = NULL;
                r->next = s;//连接到C链表中
                r = r->next;
            }
            q = q->next;
        }
        p = p->next;
    }
}

int main(){
    LinkList A = List_RearInsert(A);
    LinkList B = List_RearInsert(B);
    LinkList A = HeadInit(A);
    LinkList B = HeadInit(B);
    LinkList C = HeadInit(C);
    ListPrint(A);
    ListPrint(B);
    Intersection(A,B,C);
    Line();
    ListPrint(C);
    return 0;
}