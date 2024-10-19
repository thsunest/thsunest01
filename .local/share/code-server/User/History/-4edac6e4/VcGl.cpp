#include "LinkList.h"
void Del(LinkList &L){
    LNode *p = L->next;
    LNode *pre = L;
    LNode *q;
    int data = |p->data|;
    int firstdata = 0;
    int flag = 0;
    while(p != NULL){
        if(|pre->data| == p->data)
        firstdata = |p->data|;
        q = p;
        p = p->next;
        pre = p;
        free(q);
        if(firstdata == |p->next|)
        
    }
}
int main(){
    LinkList A = List_RearInsert(A);
}