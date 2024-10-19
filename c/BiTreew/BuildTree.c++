#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* createNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

TreeNode* buildTree(int* arr, int size) {
    if (size == 0) return NULL;

    TreeNode** nodes = (TreeNode**)malloc(size * sizeof(TreeNode*));
    for (int i = 0; i < size; i++) {
        if (arr[i] != -1) { // -1表示空节点
            nodes[i] = createNode(arr[i]);
        } else {
            nodes[i] = NULL;
        }
    }

    for (int i = 0; i < size; i++) {
        if (nodes[i] != NULL) {
            if (2 * i + 1 < size) {
                nodes[i]->left = nodes[2 * i + 1];
            }
            if (2 * i + 2 < size) {
                nodes[i]->right = nodes[2 * i + 2];
            }
        }
    }

    TreeNode* root = nodes[0];
    free(nodes);
    return root;
}

int main() {
    int arr[100];
    int size = 0;

    printf("请输入层序遍历的节点值（-1表示空节点，以-1结束输入）：\n");
    while (1) {
        int val;
        scanf("%d", &val);
        if (val == -1) break;
        arr[size++] = val;
    }

    TreeNode* root = buildTree(arr, size);
    printf("构建的二叉树的前序遍历为：\n");
    printTree(root); // 输出树的前序遍历

    return 0;
}