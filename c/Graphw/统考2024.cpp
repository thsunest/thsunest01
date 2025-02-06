#include"MGraph.h"
int isunique(MGraph G){
    int degree[G.vexnum];   //记录各个顶点的入度
    int count = 0;
    int index = 0;
    for(int i = 0; i < G.vexnum;i++){
        degree[i] = 0;
    }
    for(int i = 0;i < G.vexnum;i++){    //统计各个顶点的入度
        for(int j = 0;j < G.vexnum;j++){
            if(G.edge[i][j])
            degree[j]++;
            count++;
            index = j; //记录入度为零的结点
        }
    
    if(count == 1||count == 0)
    return 0;
    degree[index] = -1;

    for(int i = 0;i < G.vexnum;i++){
        if(G.edge[index][i] == 1){
            degree[i]--; //删除入度为0顶点的出边节点的入度
        }
    }
    }
    return 1;
}
int main(){
            //有向图邻接矩阵
    MGraph *G2 = createGraph(4);
    //定义顶点
    G2->vex[1] = 'a';
    G2->vex[2] = 'b';
    G2->vex[3] = 'c';
    G2->vex[4] = 'd';
    //定义有向边
    G2->edge[1][2] = 1;
    //G2->edge[1][4] = 1;
    G2->edge[2][3] = 1;
    //G2->edge[2][4] = 1;
    G2->edge[3][4] = 1;
    cout << isunique(*G2) << endl;


    return 0;
}