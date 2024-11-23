/*求K顶点
K顶点：岀度大于入度的顶点成为K顶点
输出K顶点
返回K顶点的个数
*/
#include"MGraph.h"
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
    G2->edge[1][4] = 1;
    G2->edge[2][3] = 1;
    G2->edge[2][4] = 1;
    G2->edge[3][4] = 1;
    cout << printVertices(*G2) << endl;

    return 0;
}
