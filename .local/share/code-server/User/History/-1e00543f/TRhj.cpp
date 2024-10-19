#include"LinkList.h"
void Intersection(LinkList A,LinkList B,LinkList &C){
    LNode *p = A->next;
    LNode *q = B->next;
    LNode *r = C;
    //扫描A链表
    while(p){
        q = B->next;//重置q指针到B链表开头
        while(q){
            if(p->data == q->data){
                LNode *check = C->next;//检查是否重复
                int found = 0;
                while(check){
                    if(check->data == p->data){
                    found = 1;
                    break;
                    }
                    check = check->next;
                }
                if(!found){
                    LNode *s = (LNode*)malloc(sizeof(LNode));
                    if(s){
                        s->data = q->data;
                        s->next = NULL;
                        r->next = s;//连接到C链表中
                        r = r->next;
                    }
                }
            }
        q = q->next;
        
        }
        p = p->next;
    }
}

int main(){
    LinkList A = HeadInit(A);
    LinkList B = HeadInit(B);
    LinkList C = HeadInit(C);
    A = List_RearInsert(A);
    B = List_RearInsert(B);
    ListPrint(A);
    ListPrint(B);
    Intersection(A,B,C);
    TestPrint(C);
    return 0;
}