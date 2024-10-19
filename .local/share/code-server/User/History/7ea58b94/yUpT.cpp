#include "LinkList.h"
LinkList Reverse(LinkList &L){
    LNode *p = L->next;
    LNode *r = p->next;
    LNode *pre;
    while(r != NULL){
        pre = p;
        p = r;
        r = r->next;
        p->next = pre;
    }
    L->next = p;
    return L;
}
int main(){
    LinkList A = List_RearInsert(A);
    ListPrint(A);
    TestPrint(Reverse(A));
    return 0;
}