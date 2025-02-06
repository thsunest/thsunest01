#include"MGraph.h"
void DFS(MGraph G,int vexIndex,int visited[]){
    visited[vexIndex] = true;
        for(int i= 0;i < G.vexnum;i++){
            if(visited[i] == false && G.edge[vexIndex][i] == 1){
                visited[i] = true;
                DFS(G,i,visited);
            }
        }    
}
int isConnected(MGraph G){
    int count = 0;
    int visited[G.vexnum];
    for(int i;i < G.vexnum;i++){
        visited[i] = 0;
    }
    DFS(G,0,visited);
    for(int i = 0;i < G.vexnum;i++){
        if(visited[i] == false){
            DFS(G,i,visited);
            count++;
        }
    }
    return count;
}
int main(){

        //无向图，邻接矩阵
    MGraph *G = createGraph(5);

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
    cout<< isConnected(*G) << endl;

    return 0;
}
