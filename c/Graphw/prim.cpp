#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5 // 顶点数量

// 找到未包含在 MST 中且具有最小权值的顶点
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX;
    int minIndex;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// 打印生成的最小生成树
void printMST(int parent[], int graph[V][V]) {
    printf("边 \t权值\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}

// Prim 算法
void primMST(int graph[V][V]) {
    int parent[V]; // 保存最小生成树的结构
    int key[V];    // 用于选择最小权值边的权值
    bool mstSet[V]; // 用于标记已经包含在最小生成树中的顶点

    // 初始化 key 值和 mstSet
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0; // 从第一个顶点开始
    parent[0] = -1; // 第一个节点作为根节点

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet); // 选择最小权值的顶点
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u, key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main() {
    // 示例图的邻接矩阵表示
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}