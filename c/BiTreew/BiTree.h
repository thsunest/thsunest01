#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;
//二叉树结点结构体
typedef struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
//创建二叉树结点
TreeNode *createNode(int value){
    if(value == -1){
        return NULL;
    }
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = value;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}
//辅助遍历链式队列结点定义
typedef struct QueueNode{
    TreeNode *treeNode;
    struct QueueNode *next;
}QueueNode;
//链式遍历队列结构
typedef struct Queue{
    QueueNode *front;
    QueueNode *rear;
}Queue;
void enQueue(Queue * queue,TreeNode * treeNode){
    QueueNode * newQueueNode = (QueueNode *)malloc(sizeof(QueueNode));
    newQueueNode->treeNode = treeNode;
    newQueueNode->next = NULL;
    if(queue->rear == NULL){
        queue->front = queue->rear = newQueueNode;
    }
    else{
        queue->rear->next = newQueueNode;
        queue->rear = newQueueNode;
    }
}
TreeNode* dequeue(Queue* queue) {
    if (queue->front == NULL) {
        return NULL;
    }
    QueueNode* temp = queue->front;
    TreeNode* node = temp->treeNode;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return node;
}

int isQueueEmpty(Queue* queue) {
    return queue->front == NULL;
}
TreeNode *insertNode(TreeNode *root,int value){
    if(!root){
    return createNode(value);
    }
    if(value < root->data){
        root->left = insertNode(root->left,value);
    }
    else if(value > root->data){
        root->right = insertNode(root->right,value);
    }
    return root;
}

//获取二叉树的树高
int getHeight(TreeNode *root){
    if(!root)
    return 0;
    int rightHeight = getHeight(root->right);
    int leftHeight = getHeight(root->left);
    return (rightHeight > leftHeight ? rightHeight :leftHeight) + 1;
}
//二叉树递归打印
void  printTree(TreeNode *root,int space,int direction){
    if(!root)
    return;

    space += 5;
    printTree(root->right,space,1);
    //printf("\n");
    for(int i = 5;i < space - 2;i++){
        printf(" ");
    }
    if (direction == 1) { // 右子树
        printf("┌───");
    } else if (direction == -1) { // 左子树
        printf("└───");
    }
    printf("%d\n",root->data);
    printTree(root->left,space,-1);

}


