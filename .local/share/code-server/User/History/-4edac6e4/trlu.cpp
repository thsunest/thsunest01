#include "LinkList.h"
void Del(LinkList &L){
    LNode *p = L->next;
    int data = |p->data|;
    int flag = 0;
    while(p != NULL){
        data = |p->data|;
        p = p->next;
    }
}
int main(){
    LinkList A = List_RearInsert(A);
}