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
void push(Stack *stack,BiTNode *treeNode){
    StackNode *newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->treeNode = treeNode;
    newNode->next = stack->top;
    stack->top = newNode;
}
void pop(Stack *stack,BiTNode *&node){
    if(stack->top == NULL) return;
    StackNode *temp = stack->top;
    BiTNode *treeNode = temp->treeNode;
    stack->top = stack->top->next;
    free(temp);
}
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
//层次遍历
void levelOrder(BiTree T){
    Queue * Q = createQueue(); // InitQueue(Q);
    BiTNode *p = T;
    enQueue(Q,p);
    while(!isEmpty(Q)){
        deQueue(Q,p);
        visit(p);
        if(p->lchild)
        enQueue(Q,p->lchild);
        if(p->rchild)
        enQueue(Q,p->rchild);
    }
}
//先序遍历，递归
void preOrder(BiTree T){
    if(T == NULL) return;
    visit(T);
    preOrder(T->lchild);
    preOrder(T->rchild);
}
//中序遍历，递归
void inOrder(BiTree T){
    if(T == NULL) return;
    inOrder(T->lchild);
    visit(T);
    inOrder(T->rchild);
}
//后续遍历，递归
void postOrder(BiTree T){
    if(T == NULL) return;
    postOrder(T->lchild);
    postOrder(T->rchild);
    visit(T);
}
//求树高
int treeHeight(BiTree T){
    if(T == NULL) return 0;
    int left = treeHeight(T->lchild);
    int right= treeHeight(T->rchild);
    return (left > right ? left : right) + 1;
}
//求树宽
int width[MAX];
void treeWidth(BiTree T,int level){
    if(T == NULL) return;
    width[level]++;
    treeWidth(T->lchild,level + 1);
    treeWidth(T->rchild,level + 1);
}
int getWidth(BiTree T){
    for(int i = 0; i < MAX; i++) //初始化数组
        width[i] = 0;
        treeWidth(T,0);
    int maxWidth = 0;
    for(int i = 0;i < MAX;i++){ //从数组中找到最大值
        if(width[i] > maxWidth)
        maxWidth = width[i];
    }
    return maxWidth;
}


void cvisit(BiTNode *p);

//判断是否为完全二叉树
bool iscomplete = true;
bool flag = false; //
void isComplete(BiTree T){
    Queue *Q = createQueue();//initQueue;
    BiTNode *p = T;
    enQueue(Q,T);
    while(!isEmpty(Q)){        
        deQueue(Q,p);
        cvisit(p);
        if(p->lchild)
        enQueue(Q,p->lchild);
        if(p->rchild)
        enQueue(Q,p->rchild);
    }
}
void cvisit(BiTNode *p){
    if(p->lchild == NULL && p->rchild == NULL) flag = true;//左右孩子都空，叶子节点
    if(p->lchild == NULL && p->rchild != NULL) iscomplete = false;//左空右有，直接就是非完全二叉树
    if(p->lchild != NULL && p->rchild == NULL){
        if(flag) iscomplete = false;//左有右空，前置结点为叶节点，非完全二叉树
        flag = true;
    }
    if(p->lchild != NULL && p->rchild != NULL)//左右都有，前置结点为叶结点或左有右空，非完全二叉树
    if(flag) iscomplete = false;
}
//逆序层序遍历二叉树
void ReverseLevelOrder(BiTree T){
    Queue *Q = createQueue();
    Stack *S = createStack();
    BiTNode *p = T;
    enQueue(Q,p);
    while(!isEmpty(Q)){
        deQueue(Q,p);
        push(S,p);
        if(p->lchild){
            enQueue(Q,p->lchild);
        }
        if(p->rchild){
            enQueue(Q,p->rchild);
        }
    }
    while(!isEmptyStack(S)){
        pop(S,p);
        visit(p);
    }
}
int main(){
    BiTree T = createNode(1);
    T->lchild = createNode(2);
    T->lchild->lchild = createNode(4);
    T->lchild->rchild = createNode(5);
    T->rchild = createNode(3);
    T->rchild->lchild = createNode(6);
    T->rchild->rchild = createNode(7);
    //levelOrder(T);
    //preOrder(T);
    //inOrder(T);
    //postOrder(T);
    // isComplete(T);
    // cout << iscomplete << endl;
    ReverseLevelOrder(T);
} 