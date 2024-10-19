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
    
}