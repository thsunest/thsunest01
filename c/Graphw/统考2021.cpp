#include"MGraph"
#include<iostream>
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
    cout << IsExistEL(*G) <<endl;
    return 0;
}
