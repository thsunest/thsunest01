#include "BiTree.h"
typedef struct{
    TreeNode *node;
    TreeNode *next;
    int top;
}Stack;
//后序遍历访问二叉树
void visit(int data){
    cout << data;
}
void swap(TreeNode &T){
        if(T){
        swap(T->left);
        swap(T->right);
        temp = T->right;
        T->right = T->left;
        T->left = temp;
    }
}
void PostOrder(TreeNode T){

}
int main(){
    int arr[] = {1,2,3,4,5,5,6,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    //TreeNode *root = buildTree(arr,size);
    //printTree(root,0,0);
    TreeNode *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left=createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    printTree(root,1,0);

}