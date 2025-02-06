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
//先序遍历非递归算法
void preOder2(BiTree T){
    Stack *S = createStack();
    BiTNode *p = T;
    while(p || !isEmptyStack(S)){
        if(p){
            visit(p);
            push(S,p);
            p = p->lchild;
        }
        else{
            pop(S,p);
            p = p->rchild;
        }
    }
}
//中旬遍历非递归算法
void inOrder2(BiTree T){
    Stack *S = createStack();
    BiTNode *p = T;
    while(p || !isEmptyStack(S)){
        if(p){
            push(S,p);
            p = p->lchild;
        }
        else{
            pop(S,p);
            visit(p);
            p = p->rchild;
        }
    }
}
//后序遍历非递归算法
void postOrder2(BiTree T){
    Stack *S = createStack();
    BiTNode *p = T;
    BiTNode *r = NULL; //记录结点是否被访问过
    while(p || !isEmptyStack(S)){
        if(p){
            push(S,p);
            p = p->lchild; //向左压栈
        }
        else{
            GetTop(S,p);
            if(p->rchild&&p->rchild != r)
                p = p->rchild; //转向右
            else{
            pop(S,p);
            visit(p);
            r = p;
            p = NULL; //节点访问完后重置p指针
            }
        }
    }
}
//
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
//判断是否为二叉排序树（BST），中序遍历，保证 左<=根<=右
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
//判断二叉树是否平衡，后序遍历，左右子树高度之差不小于1
bool isblance = true;
int isBlance(BiTree T){
    if(T == NULL)  return 0;
    int left = isBlance(T->lchild);
    int right = isBlance(T->rchild);
    if(left - right > 1) isblance = false;
    if(left - right < -1) isblance = false;
    return (left > right ? left + 1 : right +1);


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

int main(){
    /*BiTree T = createNode(1);
    T->lchild = createNode(2);
    T->lchild->lchild = createNode(4);
    T->lchild->rchild = createNode(5);
    T->rchild = createNode(3);
    T->rchild->lchild = createNode(6);
    T->rchild->rchild = createNode(7);
    */
    BiTree T = createNode(4);
    T->lchild = createNode(2);
    T->lchild->lchild = createNode(1);
    T->lchild->rchild = createNode(3);
    T->rchild = createNode(6);
    T->rchild->lchild = createNode(5);
    T->rchild->rchild = createNode(7);
   //8 T->rchild->rchild->rchild = createNode(7);
   // T->rchild->rchild->rchild->rchild = createNode(7);
    

    //levelOrder(T);
    //preOrder(T);
    //inOrder(T);
    //postOrder(T);
    // isComplete(T);
    // cout << iscomplete << endl;
    //printTree(T,1,0);
    //levelOrder(T);
    //ReverseLevelOrder(T);
    //treeWidth(T,1);

    //cout << getWidth(T) << endl;
    //inOrder(T);
    //inOrder2(T);
    //postOrder(T);
    //postOrder2(T);
    // isBST(T);
    // cout<< isbst <<endl;
    printTree(T,1,0);
    isBlance(T);
    cout<< isblance << endl;
} 