#include"BiTree.h"
int simulate(BiTNode *T1,BiTNode *T2){
    int left,right;
    if(T1 == NULL&&T2 == NULL)
    return 1;
    if(T1 == NULL ||T2 == NULL)
    return 0;
    else{
        left = simulate(T1->lchild,T2->lchild);
        right = simulate(T1->rchild,T2->rchild);
        return (left&&right);
    }
}
int main(){
    BiTNode *T1 = createNode(1);
    T1->lchild = createNode(2);
    T1->rchild = createNode(3);
    T1->lchild->lchild=createNode(4);
    T1->lchild->rchild = createNode(5);
    T1->rchild->lchild = createNode(6);
    T1->rchild->rchild = createNode(7);
    printTree(T1,1,0);
    BiTNode *T2 = createNode(1);
    T2->lchild = createNode(2);
    T2->rchild= createNode(3);
    T2->lchild->lchild=createNode(4);
    T2->lchild->rchild = createNode(5);
    T2->rchild->lchild = createNode(6);
    T2->rchild->rchild = createNode(7);
    T2->rchild->rchild->rchild = createNode(7);
    printTree(T2,1,0);
    cout << simulate(T1,T2) <<endl;


}





