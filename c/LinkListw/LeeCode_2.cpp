/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p = l1;
    struct ListNode *q = l2;
    int length1 = 0;
    int length2 = 0;
    int flag = 0; //进位信号
    while(p){    //求表长
        length1++;
        p = p->next;
    }
    while(q){
        length2++;
        q = q->next;
    }
    struct ListNode* Q;
    struct ListNode* P;
    struct ListNode* F;      
    
    if(length1 > length2){
        F = q = Q = l1;
        P = l2;
    }
    else{
        F = q = Q = l2;
        P = l1;
    }//比较两个链表的长度，较长的作为主链表Q  
    while(Q){
        Q->val = Q->val + P->val;
        if(Q && Q->val >= 10){Q->val-=10; flag++;}
        if(P->next){P = P->next;}
        Q = Q->next;
        if(Q && flag != 0){
            Q->val++;
            flag--;
            if(Q->val >= 10){Q->val -=10;flag++;}
        }
    }
    if(flag != 0){
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        
        newNode->val++;
        Q = newNode;
    }
    printf(Q->val);
    
    return q;
   
    
}
    LNode *node2 = (LNode *)malloc(sizeof(LNode));
    LNode *node3 = (LNode *)malloc(sizeof(LNode));
    node1->data = 9;
    node2->data = 9;
    node3->data = 9;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    LNode *A = node1;
    LNode *node4 = (LNode *)malloc(sizeof(LNode));
    LNode *node5 = (LNode *)malloc(sizeof(LNode));
    node4->data = 9;
    node5->data = 9;
    node4->next = node5;
    node5->next =NULL;
    LNode *B = node4;


    LNode *C =(LNode *)malloc(sizeof(LNode));
    C = add(A,B);
    ListPrint(C);
    return 0;
}