#include <stdio.h>
#include <stdlib.h>
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
LinkList HeadInitLinkList(LinkList &L){
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)    //内存不足
        return NULL;
    L ->next = NULL;
    return L;
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
    return true;
}
//不带头结点的判空操作
bool Empty(LinkList L){
    if(L == NULL)
        return true;
    else
        return false;
}
//求表长操作
int Length(LinkList L){
    int len = 0;
    LNode *p = L;
    while(p -> next != NULL){
        p = p->next;
        len ++;
    }
    return len;
}
//按序号查找节点
LNode *GetElem(LinkList L,int i){
    LNode *p = L;
    int j = 0;
    while(p != NULL && j < i){
        p = p->next;
        j++;
    }
    return p;
}
//插入节点
bool ListInsert(LinkList &L,int e,int i){
    int j = 0;
    LNode *p = L;
    while(p != NULL && j < i -1){
        p = p->next;
        j++;
    }
    if(p == NULL)
    return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
//删除节点
bool ListDel(LinkList &L,int i,int &value){
    LNode *p = L;
    int j = 0;
    while(p != NULL && j < i-1){
        p = p->next;
        j++;
    }
    if(p == NULL ||p->next == NULL)
    return false;
    LNode *q = p->next;
    value = q->data;
    p->next = q->next;
    free(q);
    return true;
}

bool FreeNode(LNode **node){
    if(node && *node){
    LNode *temp = *node;
    *node = (*node)->next;
    free(temp);
    return true;
    }
    return false;

}
//头插法建立单链表
LinkList List_HeadInsert(LinkList &L){
    LNode *s;
    int x;
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d",&x);
    while(x != 9999){
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d",&x);
    }
    return L;
}
//尾插法建立单链表
LinkList List_RearInsert(LinkList &L){
    int x;
    L = (LNode*)malloc(sizeof(LNode));
    LNode *s,*r = L;
    scanf("%d",&x);
    while(x != 9999){
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d",&x);
    }
    return L;

}
void ListPrint(LinkList L){
    LNode *p = L;
    while(p != NULL){
        printf("%d->",p->data);
        p = p->next;
    }
    printf("\n");
}
void MergeList(LinkList &La,LinkList &Lb,LinkList &Lc){
    LNode *pa = La->next;
    LNode *pb = Lb->next;
    Lc = La;
    LNode *pc = Lc;
    while(pa && pb){
        if(pa->data < pb->data){
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else if(pb->data < pa->data){
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
        else if(pa->data == pb->data){
            pc->next = pa;
            pc = pa;
            pa = pa->next;
            LNode *q;
            q = pb->next;
            free(pb);
            pb = q;
        }
        /*  if(pa){
        pc->next = pa;
        }
        else{
        pc->next = pb;
        free(Lb);
        Lb = NULL;
        }
        等价*/
        pc->next = pa?pa:pb;

        }

}
void Intersection(LinkList &La,LinkList &Lb,LinkList &Lc){
    LNode *pa = La->next;
    LNode *pb = Lb->next;
    Lc = La;
    LNode *pc = Lc;
    while(pa && pb){
        if(pa->data == pb->data){
            pc->next = pa;
            pc = pa;
            pa = pa->next;
            //删除B中相同的结点
            /*LNode *q = pb;
            pb = pb->next;
            free(q)
            */
            FreeNode(&pb);
        }
        else if(pa->data < pb->data){
            /*LNode *q = pa;
            pa = pa->next;
            free(q);
            */
            FreeNode(&pa);
        }
        else
        {
            /*LNode *q = pb;
            pb = pb->next;
            free(q);
            */
            FreeNode(&pb);
        
        }
    }
    while(pa){
        /*LNode *q;
        q = pa;
        pa = pa->next;
        free(q);
        */
        FreeNode(&pa);   
    }
    while(pb){
        /*LNode *q;
        q= pb;
        pb = pb->next;
        free(q);
        */
        FreeNode(&pb);
    }
    pc->next = NULL;//设置链表C的最后一个节点的next指针域
    free(Lb);//B的头节点多余，可以删除

}
//在A中删除A和B共有的元素
void Difference(LinkList &La,LinkList &Lb,int &len){
    LNode *pa = La->next;
    LNode *pb = Lb->next;
    LNode *pre = (LNode *)malloc(sizeof(LNode));
    while(pa && pb){
        if(pa->data < pb->data){
            pre = pa;
            pa = pa->next;
        }
        else if(pb->data < pa->data){
            pb = pb->next;
        }
        else{
            pre->next = pa->next;
            FreeNode(&pa);
        }
    }
    len = Length(La);
}
LinkList Del_Min(LinkList &L){
    LNode *pre = L;
    LNode *p = L->next;
    LNode *minp = p;
    LNode *minpre = pre;
    while(p != NULL){
        if(p->data < minp->data){
            //记录扫描到的最小元素及其前驱
            minp = p;
            minpre = pre;
        }
        pre = p;
        p = p->next;
        }
        minpre->next = minp->next;
        free(minp);
        return L;
}
LinkList Del_Max(LinkList &L){
    LNode *pre = L;
    LNode *p = L->next;
    LNode *maxp = p;
    LNode *premaxp = pre;
    while(p != NULL){
        if(p->data > maxp->data){
            maxp = p;
            premaxp = pre;
        }
        pre = p;
        p = p->next;
    }
    premaxp->next = maxp->next;
    free(maxp);
    return L;
}
LinkList Del_X(LinkList &L,int x){
    LNode *p = L->next;
    LNode *pre = L;
    LNode * q;
    while(p != NULL){
        if(p->data == x){
            q = p;
            pre->next = p->next;
            p = p->next;
            free (q);
        }
        else{
            pre = p;
            p = p->next;
        }
    }
    return L;
}
LinkList Del_From(LinkList &L,int a,int b){
    LNode *p = L->next;
    LNode *pre = L;
    LNode *q;
    while(p != NULL){
        if(p->data > a && p->data <b){
            q = p;
            pre->next = p->next;
            p = p->next;
        }
        else{
        pre = p;
        p = p->next;
        }
    }
    return L;
}
LinkList Reverse(LinkList L){
    LNode *pre = L;
    LNode *current = L->next;
    LNode *next = NULL;
    L->next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = pre;
        pre =current;
        current = next;

    }
    return pre;
}
LinkList DisCreat(LinkList &A){
    LinkList B = (LinkList)malloc(sizeof(LNode));
    B->next = NULL;
    LNode *ra = A;
    LNode *rb = B;
    LNode *p = A->next;
    A->next = NULL;
    int i = 0;
    while(p != NULL){
        i++;
        if(i % 2 == 0){
            ra->next = p;
            ra = p;  
        }
        else{
            rb->next = p;
            rb = p;
        }
        p->next = p;
    }
    return B;
}
int main(){
    //ListInsert(L,1,6);
    //LinkPrint(L);
    //int value;
    //ListDel(L,2,value);
    //printf("\n-------------\n");
    //LinkPrint(L);
    //List_HeadInsert(S);
    //LinkList S = List_RearInsert(S);
    //LinkPrint(S);
    LinkList A = List_RearInsert(A);
    //LinkList B = List_RearInsert(B);
    //LinkList C = HeadInitLinkList(C);

    //MergeList(A,B,C);
    //ListPrint(C);    
    ListPrint(A);    
    //ListPrint(B);
    printf("------------------------------\n");

    //MergeList(A,B,C);
    //Intersection(A,B,C);
    //int len = 0;
    //Difference(A,B,len);
    //Del_Min(A);
    //Del_Max(A);
    //Del_X(A,10);
    //Del_From(A,1,10);
    //LinkList B = Reverse(A);
    //ListPrint(B);
    LinkList B = DisCreat(A);
    ListPrint(A);
    ListPrint(B);




    //len = Length(L);
    //printf("\n表长：%d",len);
    return 0;
}