#include "MGraph.h"
#include <iostream>
using namespace std;
//无向图求顶点的度
int MGraph_D(MGraph G,int vex){
    int d = 0;
    for(int i = 0;i < MAXV;i++){
        if(G.edge[vex][i] != 0){
            d++;
        }
    }
    return d;
}
//有向图求岀度，入度
int MGraphOutD(MGraph G,int vex){
    int d = 0;
    for(int i = 0;i <MAXV;i++){
        if(G.edge[vex][i] != 0){
            d++;
        }
    }
    return d;
}
int MGraphInD(MGraph G,int vex){
    int d = 0;
    for(int i = 0;i < MAXV;i++){
        if(G.edge[i][vex] != 0){
            d++;
        }
    }
    return d;
}
//统考2023
int printVertices(MGraph G){
    int k_num = 0;
    for(int i = 0;i < MAXV; i++){
        if(MGraphOutD(G,i) > MGraphInD(G,i)){
            k_num++;
            cout << G.vex[i] << endl;
        }

    }
    return k_num;
}
//统考2021
int IsExistEL(MGraph G){
    int d = 0;
    int cout = 0;
    for(int i= 0;i < MAXV;i++){
        d = MGraph_D(G,i);
        if(d % 2 == 1)
        cout++;
    }
    if(cout % 2 == 0&& cout <=2)
    return 1;
    else return 0;
}
//DFS
void visit(MGraph G,int vexIndex){
    cout << G.vex[vexIndex] << endl;

}
bool visited[MAXV];
void DFS(MGraph G,int vexIndex){
    visit(G,vexIndex);
    visited[vexIndex] = true;
    for(int i = 0; i < MAXV;i++){
        if(G.edge[vexIndex][i] == 1 && visited[i]== false){
            DFS(G,i);
        }
    }
}
//BFS
void BFS(MGraph G,int vexIndex){
    Queue *Q;
    initQueue(Q);
    visit(G,vexIndex);// 访问初始结点
    visited[vexIndex] = true; //标记该结点已经被访问过
    enQueue(Q,vexIndex);
    while(!isEmpty(Q)){
        deQueue(Q,vexIndex);
        for(int i = 0; i< G.vexnum;i++){
            if(visited[i] == false&&G.edge[vexIndex][i] == 1){ //i如果是未被访问过的结点，且被前继结点所指
                visit(G,i);
                visited[i] = true;
                enQueue(Q,i);
            }
        }
    }
}
//BFS求单源最短路径问题
#define INF -1
void BFS_MinDistence(MGraph G,int u){
    int d[G.vexnum];
    Queue *Q;
    initQueue(Q);
    for(int i;i < G.vexnum;i++){
        d[i] = INF;
        path[i] = -1;
    }
    d[u] = 0;
    visited[u] = true;
    enQueue(Q,u);
    while(!isEmpty(Q)){
        deQueue(Q,u);
        
    }
}
//判断无向图是否连通
int isConnected (MGraph G){
    int visited[G.vexnum];
    for(int i = 0;i < G.vexnum;i++){
        visited[i] = 0;
    }
    BFS(G,0);
    for(int i = 0;i < G.vexnum;i++){
        if(visited[i] == 0)
        return 0;
        else
        return 1;
    }

}
int main(){
    MGraph *G = createGraph(5);
    //无向图，邻接矩阵
    G->edge[0][1] = 1;  G->vex[0] = '0';
    G->edge[0][1] = 1;
    G->edge[0][2] = 1;
    G->edge[0][4] = 1;
    G->edge[1][0] = 1;  G->vex[1] = '1';
    G->edge[1][3] = 1;
    G->edge[1][4] = 1;
    G->edge[2][0] = 1;  G->vex[2] = '2';
    G->edge[2][3] = 1;
    G->edge[3][1] = 1;  G->vex[3] = '3';
    G->edge[3][2] = 1;
    G->edge[3][4] = 1;
    G->edge[4][0] = 1;  G->vex[4] = '4';
    G->edge[4][1] = 1;
    G->edge[4][3] = 1;
    //有向图邻接矩阵
    MGraph *G2 = createGraph(4);
    //定义顶点
    G2->vex[1] = 'a';
    G2->vex[2] = 'b';
    G2->vex[3] = 'c';
    G2->vex[4] = 'd';
    //定义有向边
    G2->edge[1][2] = 1;
    G2->edge[1][4] = 1;
    G2->edge[2][3] = 1;
    G2->edge[2][4] = 1;
    G2->edge[3][4] = 1;
    // cout << MGraph_D (*G,1) <<endl;
    // cout << printVertices(*G2) << endl;
    // DFS(*G,1);
    // cout << IsExistEL(*G) <<endl;
    BFS(*G,2);
    cout << isConnected(*G) << endl;
    return 0;
}