#include "LinkList.h"
void Del(LinkList &L){
    LNode *p = L->next;
    LNode *pre = L;
    LNode *q;
    int data = |p->data|;
    int flag = 0;
    while(p != NULL){
        if(|pre->data| == p->data)
        
        p = p->next;
        pre = p;
        
    }
}
int main(){
    LinkList A = List_RearInsert(A);
}