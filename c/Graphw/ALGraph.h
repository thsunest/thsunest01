#include<stdio.h>
#include<iostream>
#define MaxVertexnum 100
typedef struct ArcNode{ //边表结点
    int adjvex; //该弧指向顶点的位置
    struct ArcNode *nextarc;//指向下一条弧的指针
    InfoType info;//网的权值
}ArcNode;
typedef struct VNode{//顶点表结点
    VertexType data; //顶点信息
    ArcNode *firstarc; //指向第一条依附该顶点的弧的指针
}VNode,AdjList[MaxVertexnum];
typedef struct{
    AdjList vertices; //邻接表
    int vexnum,arcnum;//图的顶点数和弧数
}ALGraph;