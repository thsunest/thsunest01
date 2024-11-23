#include<stdio.h>
#include<iostream>
#define MAXV 100 //MaxVertexNum
using namespace std;

typedef char VertexType;
typedef int EdgeTyepe;
typedef struct{
    VertexType vex[MAXV];//顶点表
    EdgeTyepe edge [MAXV][MAXV];//邻接矩阵
    int  vexnum,arcnum;//当前定点数，边数
}MGraph;
MGraph *createGraph(int vexnum){
    MGraph *G = (MGraph*)malloc(sizeof(MGraph));
    G->vexnum = vexnum;
    for(int i = 0;i < MAXV;i++)
        for(int j = 0;j < MAXV;j++)
            G->edge[i][j] = 0;
    return G;
}
//辅助队列结构
typedef struct{
    int items[MAXV];
    int front;
    int rear;
}Queue;
//初始化队列
void initQueue(Queue *q){
    q->front = -1;
    q->rear = -1;
}
//判断队列是否为空
bool isEmpty(Queue *q){
    return q->front == -1;
}
//入队
void enQueue(Queue *q,int value){
    if(q->rear == MAXV - 1)
    return;
    if(q->front == -1)
    q->front = 0;
    q->items[++q->rear] = value;
}
//出队
void deQueue(Queue *q,int &value){
    if(isEmpty(q)) return; //队列为空，直接返回
    int item = q->items[q->front];
    if(q->front == q->rear){//队列中所有元素都已出队
        q->front = -1;
        q->rear = -1;
    }
    else{
        q->front++;
    }
    value = item;
}
// 求顶点的岀度
int MGraphOutD(MGraph G,int vex){
    int d = 0;
    for(int i = 0;i <MAXV;i++){
        if(G.edge[vex][i] != 0){
            d++;
        }
    }
    return d;
}
// 求顶点的入度
int MGraphInD(MGraph G,int vex){
    int d = 0;
    for(int i = 0;i < MAXV;i++){
        if(G.edge[i][vex] != 0){
            d++;
        }
    }
    return d;
}


