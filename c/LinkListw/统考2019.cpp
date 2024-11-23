#include<iostream>
#include"LinkList.h"
#include<algorithm>
using namespace std;
LNode * FindMid(LNode *L){
    LNode *fast = L->next->next;
    LNode *slow = L->next;
    while(fast){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
LNode* Reverse(LNode *L){
    LNode *curr = L->next;
    LNode *prev = NULL;
    while(curr){
        LNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
void Merge(LNode *L){
    int count = 0;
    LNode *p = L->next;
    LNode *q = FindMid(L);
    LNode *second = q->next;
    second == Reverse(second);
    q->next =NULL;
    while(p){
        if(count % 2 - 1 == 0)
        p = second;

        count++;
        p = p->next;
        second = second->next;

    }
}
int main(){
    LNode *head = createHead();
    append(head,4);
    append(head,3);
    append(head,5);
    append(head,2);
    append(head,1);
    append(head,45);
    append(head,12);
    ListPrint(head);
    Merge(head);
    Line();
    ListPrint(head);
    return 0;
}