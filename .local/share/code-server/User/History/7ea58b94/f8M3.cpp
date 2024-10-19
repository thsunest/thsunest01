#include "LinkList.h"
LinkList Reverse(LinkList &L){
    LNode *p = L->next;
    LNode *r = p->next;
    LNode *pre;
    while(r != NULL){
        
        p = r;
        r = r->next;


    }
}