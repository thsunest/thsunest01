#include <stdio.h>
//定义一个单链表
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;
/*等价于
typedef struct LNode LNode;   struct LNode 等价于 LNode;
typedef struct Lnode *LinkList; LNode *L 等价于 Linklist L;
*/
//初始化一个带头节点的单链表
bool HeadInitLinkList(LinkList &L){
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)    //内存不足
        return false;
    L ->next = NULL;
    return ture;
}
//带头结点单链表的判空操作
bool HeadEmpty(LinkList L){
    if(L ->next == NULL)
        return true;
    else
        return false;
}
//初始化一个不带头节点的单链表
bool InitLinkList(LinkList &L){
    L = NULL;
}
//不带头结点的判空操作
bool Empty(LinkList L){
    if(L == NULL)
        return true;
    else
        return false;
}
int Length(LinkList L){
    int len = 0;
    LNode *p = L;
    while(p -> next != NULL){
        p = p
    }
}
int main(){
    printf("hello");
}