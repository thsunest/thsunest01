#include<stdio.h>
#include<stdlib.h>
typedef struct DNode{
    struct DNode *prior,*next;
    int data;
    int freq;
}DNode, *DLinkList;
void DLinkPrint(DLinkList L){
    DNode *p = L;
    while(p != NULL){
        printf("%d<=>",p->data);
        p = p->next;
    }
    printf("\n");

}
//头插法建立双链表
DLinkList DLink_HeadInsert(DLinkList &L){
    L = (DLinkList)malloc(sizeof(DLinkList));
    L->next = NULL;
    L->prior = NULL;
    DNode *s;
    int x;
    scanf("%d",&x);
    while(x != 9999){
        s = (DNode*)malloc(sizeof(DNode));
        s->data = x;
        s->next = L->next;
        s->prior = L;
        if(L->next != NULL){
            L->next->prior = s;
        }
        L->next = s;
        scanf("%d",&x);
    }
    return L;
}
//尾插法建立双链表
DLinkList DLink_RearInsert(DLinkList &L){
    L = (DLinkList)malloc(sizeof(DNode));
    L->next = NULL;
    L->prior = NULL;
    DNode *s;
    DNode *r = L;
    int x;
    scanf("%d",&x);
    while(x != 9999){
        s = (DNode *)malloc(sizeof(DNode));
        s->data = x;
        //s->next = NULL;
        r->next = s;
        s->prior = r;
        r = r->next;
        scanf("%d",&x);
    }
    return L;
}
//删除最大值
void DelMax(DLinkList &L){
    DNode *p = L->next;
    DNode *pre;
    DNode *post;
    DNode *maxp = p->next;
    while(p != NULL){
        if(p->data > maxp->data)//向后逐一比较，记录最大节点指针
        maxp = p;
        p = p->next;
    }
    pre = maxp->prior;
    post = maxp->next;
    pre->next = post;
    if(post != NULL)//防止空指针错误
    post->prior = pre;
    free(maxp); 
}
//删除最小值
void DelMin(DLinkList &L){
    DNode *p = L->next;
    DNode *minp = p->next;
    DNode *pre,*post;
    while(p->next != NULL){
        if(p->data < minp->data){
        minp = p;//记录最小元素指针
        }
        p = p->next;//工作指针向后移动
    }
    //双链表的删除操作，记录前后结点
    pre = minp->prior;
    post = minp->next;
    pre->next = post;//等价于pre->next = minp->next
    if(post != NULL)
    post->prior = pre;
    free(minp);
}
//连续删除
bool DelFrom(DLinkList &L,int a,int b){
    if(a >= b || L->next == NULL){
        return false;
    }
    DNode *p = L->next;
    DNode *pre = L;
    DNode *todelete;
    while(p != NULL){
        if(p->data >a && p->data <b){
            todelete = p;
            pre->next = p->next;
            if(p->next != NULL){
                p->next->prior = pre;
            }
            free(todelete);
            p = pre->next;
        }
        pre = p;
        p = p->next;
    }
    return true;
}
int LocateNode(DLinkList &L,int x){
    DNode *p = L->next;
    DNode *pre= L;
    while(p != NULL && p->data != x){//找到p结点
        p = p->next;
    }
    if(p == NULL){//如果p节点为空，返回
        return 0;
    }
    else{
        p->freq += 1;//成功访问。freq域+1
        pre = p->prior;//初始化pre指针
        if(pre != L){
            while(pre != L && pre->freq < p->freq){//pre指针向前滑动，找到freq小于p的pre节点
                pre =pre->prior;
            }
            //删除p节点
            p->prior->next = p->next;
            if(p->next != NULL){
                p->next->prior = p->prior;
            }
            //将p节点连接到pre结点的后面
            p->next = pre->next;
            if(pre->next != NULL){
                pre->next->prior = p;
            }
            pre->next = p;
            p->prior = pre;
        
        }
    }
    return 1;
}
int main(){
    //DLinkList A = DLink_HeadInsert(A);
    DLinkList A = DLink_RearInsert(A);
    DLinkPrint(A);
    //DelMax(A);
    //DelMin(A);
    //DelFrom(A,2,4);
    LocateNode(A,3);
    LocateNode(A,3);
    LocateNode(A,3);
    LocateNode(A,3);
    DLinkPrint(A);
    return 0;
}