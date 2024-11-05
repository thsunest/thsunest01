#include "BiTree.h"
#include <iostream>
using namespace std;
//非递归后序遍历求WPL算法
int WPL(BiTree T){
    int flag = 0;
    int wpl = 0;
    int f = 0;
    int level = 0; //记录层级
    Stack *S = createStack();
    BiTNode *p = T;
    BiTNode *r = NULL;
    while(p || !isEmptyStack(S)){
        if(p){
            push(S,p);
            level++;
            p = p->lchild;
        }
        else{
            GetTop(S,p);
            if(p->rchild && p->rchild != r){
                p = p->rchild;
            }
            else{
                pop(S,p);
                if(p->rchild == NULL && p->lchild == NULL){
                wpl += p->data * level;
                }
                level--;
                r = p;
                p = NULL;           
            }
        }
    }
    return wpl;
}
//递归算法求WPL
int wpl = 0;  //保存权重
int level = 0; //标记路径长度
void WPL2(BiTree T){
    if(T == NULL) return;
    BiTNode *p = T;
        level++;
        if(p->lchild)
        WPL2(p->lchild);
        if(p->rchild)
        WPL2(p->rchild);
        if(p->lchild == NULL && p->rchild == NULL) //如果为叶结点，累加路径权重
        wpl += p->data * level;
        level--;  //退栈前，减去路径长度
}
int main(){
    BiTree T = createNode(1);
    T->lchild = createNode(2);
    T->lchild->lchild = createNode(4);
    T->lchild->rchild = createNode(5);
    T->rchild = createNode(3);
    T->rchild->lchild = createNode(6);
    T->rchild->rchild = createNode(7);
    T->rchild->rchild->lchild = createNode(8);
    printTree(T,1,0);
    WPL2 (T);
    cout << wpl << endl;
    cout << WPL(T) << endl;


}