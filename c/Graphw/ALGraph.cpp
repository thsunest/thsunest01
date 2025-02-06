#include<iostream>
# V 5 //定义最大节点数
using namespace std;
typedef struct VNode{
    int data;          //结点的数据域
    struct VNode *next;//结点的指针域
}VNode;
VNode *adjList[V];      //结点数组
//初始化邻接链表
void init(){
    for(int i = 0;i < V;i++){
        adjList[i] = NULL;
    }
}
//有向图 头插法 添加边
void addEdge(int src,int dest){//src顶点编号,
    VNode newNode = (VNode *)malloc(sizeof(VNode));
    newNode->data = dest; //dest为权值
    newNode->next = adjList[src];
    adjList[src] = newnode;
}
//无向图 头插法 添加边
void addEdge2(int src,int dest){
    VNode newNode1 = (VNode *)malloc(sizeof(VNode)); //src结点到dest
    newNode1->data = dest;
    newNode1->next = adjList[src];
    adjList[src] = newNode1;

    VNode newNode2 = (VNode *)malloc(sizeof(VNode));//des结点到src
    newNode2->data = src;
    newNode2->next = adjList[dest];
    adjList[dest] =newNode2;

}
int main(){

    return 0;
}