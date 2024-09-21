#include <stdio.h>
//定义一个单链表
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;
//初始化一个带头节点的单链表
bool HeadInitLinkList(LinkList &L){
    L = (LNode *)malloc(sizeof(LNode));
    L ->next = NULL;
    return ture;

}
int main(){
    printf("hello");
}