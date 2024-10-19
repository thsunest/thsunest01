#include<stdio.h>
#include<iostream>
#define MaxVertexnum 100
using namespace std;

typedef char VertexType;
typedef int EdgeTyepe;
typedef struct{
    VertexType vex[MaxVertexnum];//顶点表
    EdgeTyepe edge [MaxVertexnum] [MaxVertexnum];//邻接矩阵
    int  vexnum,arcnum;//当前定点数，边数
}MGraph;


