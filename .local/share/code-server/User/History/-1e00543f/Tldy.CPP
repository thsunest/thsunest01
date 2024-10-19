#include"LinkList.h"
void Intersection (LinkList A,LinkList B,LinkList &C){
    LNode *p = A->next;
    LNode *q = B->next;
    LNode *r = C;
    while(p){
        while(q){
            if(p->data == q->data){
                r->next = q;
                r = r->next;
                q = q->next;
            }
            else{
                q = q->next;
            }
        }
        p = p->next;
    }
}
int main(){
    LinkList A = List_RearInsert(A);
    LinkList B = List_RearInsert(B);
    LinkList C = HeadInit(C);
    ListPrint(A);
    ListPrint(B);
    Intersection(A,B,C);
    TestPrint(C)
    return 0;
}