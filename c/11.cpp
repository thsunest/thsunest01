#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *current = head;
    struct ListNode *next = NULL;

    while (current != NULL) {
        next = current->next; // 先保存下一个节点
        current->next = prev; // 当前节点指向前一个节点，实现反转
        prev = current;      // 更新prev为当前节点
        current = next;      // 更新当前节点为下一个节点
    }

    return prev; // prev现在是反转后的头节点
}

// 辅助函数：创建新节点
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// 辅助函数：释放链表空间
void freeList(struct ListNode* head) {
    struct ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// 测试函数
int main() {
    // 创建一个链表：1 -> 2 -> 3 -> 4 -> 5
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // 打印原始链表
    struct ListNode* current = head;
    printf("Original list: ");
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");

    // 反转链表
    struct ListNode* reversedHead = reverseList(head);

    // 打印反转后的链表
    current = reversedHead;
    printf("Reversed list: ");
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");

    // 释放链表空间
    freeList(reversedHead);

    return 0;
}
