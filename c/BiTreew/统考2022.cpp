/*判断是否是二叉排序树*/
#include"BiTree.h"
bool isbst = true;
int temp = 0;
void isBST(BiTree T){
    if(T == NULL) return;
    isBST(T->lchild);
    if(T->data >= temp) //判断当前访问的根结点是否小于前继结点
    temp = T->data;
    else isbst = false;
    isBST(T->rchild);
}
int main(){
    BiTNode *root = createNode(20);
    root->lchild = createNode(5);
    root->rchild = createNode(25);
    root->lchild->lchild=createNode(4);
    root->lchild->rchild = createNode(6);
    root->rchild->lchild = createNode(21);
    root->rchild->rchild = createNode(36);
    printTree(root,1,0);
    isBST(root);
    cout<< isbst << endl;

}
