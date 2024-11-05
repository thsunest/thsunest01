#include<iostream>
#define MAX 255
using namespace std;
//二叉树结构
typedef struct BiTNode{
    struct BiTNode *lchild;
    struct BiTNode *rchild;
    int data;
}BiTNode,*BiTree;

//定义辅助队列结点结构
typedef struct QueueNode{
    BiTNode *treeNode;
    struct QueueNode *next;
}QueueNode;
//辅助队列
typedef struct Queue{
    QueueNode *rear,*front;
}Queue;
//定义辅助栈结点
typedef struct StackNode{
    BiTNode *treeNode;
    struct StackNode *next;
}StackNode;
//定义辅助栈结构
typedef struct Stack{
    StackNode *top;
}Stack;
//创建空队列
Queue* createQueue(){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL; //前后指针一致的时候，队列为空
    return q;
}
//创建栈
Stack* createStack(){
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}
//入栈
void push(Stack *stack,BiTNode *treeNode){
    StackNode *newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->treeNode = treeNode;
    newNode->next = stack->top;
    stack->top = newNode;
}
//出栈
void pop(Stack *stack,BiTNode *&node){
    if(stack->top == NULL) return;
    StackNode *temp = stack->top;
    BiTNode *treeNode = temp->treeNode;
    stack->top = stack->top->next;
    free(temp);
    node = treeNode;
}
//获取栈顶元素
void GetTop(Stack *S,BiTNode *&node){
    node = S->top->treeNode;
}
//判断栈是否为空
bool isEmptyStack(Stack *stack){
    return stack->top == NULL;
}
//入队

void enQueue(Queue *q,BiTNode *node){
    QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
    temp->treeNode = node; //新队列结点初始化
    temp->next = NULL;
    if(q->rear == NULL){
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
//出队
void deQueue(Queue *q,BiTNode *&node){
    if(q->front == NULL) return; //队列为空，直接返回
    QueueNode *temp = q->front;
    node = temp->treeNode;
    q->front = q->front->next;
    if(q->front ==NULL) q->rear = NULL; //出队后队列为空，尾指针置空
    free(temp);
}
//判断队列是否为空
int isEmpty(Queue *q){
    return q->front == NULL;
}

//创建二叉树结点
BiTNode *createNode(int data){
    BiTNode *newNode =(BiTNode *)malloc(sizeof(BiTNode));
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}
void visit(BiTNode *node){
    cout << node->data << endl;
}
void  printTree(BiTNode *root,int space,int direction){//root,0,1
    if(!root)
    return;

    space += 5;
    printTree(root->rchild,space,1);
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
    printTree(root->lchild,space,-1);
}