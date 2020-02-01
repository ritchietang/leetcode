/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 */
#include <stdio.h>
#include <stdlib.h>

// @lc code=startq
//  struct ListNode {
//     int val;
//     struct ListNode *next;
//  };

static struct ListNode * CreateNewNode(void)
{
    struct ListNode * node = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (node == NULL) {
        printf("malloc error\n");
        return NULL;
    }
    node->next = NULL;
    node->val = 0;
    return node;
}

struct ListNode* AddRecursion(struct ListNode* l1, struct ListNode* l2, int *carry)
{
    int ret;
    if (carry == NULL) {
        // printf("carry is null\n");
        return NULL;
    } else if ((l1 == NULL) && (l2 == NULL)) {
        // printf("both are null\n");
        return NULL;
    }
    struct ListNode *node = CreateNewNode();
    if (node == NULL) {
        printf("create node erorr\n");
        return NULL;
    }
    if (l1 == NULL) {
        ret = l2->val + *carry;
        node->val = ret % 10;
        *carry = ret / 10;
        l2 = l2->next;
    } else if (l2 == NULL) {
        ret = l1->val + *carry;
        node->val = ret % 10;
        *carry = ret / 10;
        l1 = l1->next;
    } else {
        // printf("[%s_%d]val1=%d, val2=%d, *carry=%d\n", __func__, __LINE__, l1->val, l2->val, *carry);
        ret = l1->val + l2->val + *carry;
        node->val = ret % 10;
        *carry = ret / 10;
        l1 = l1->next;
        l2 = l2->next;
    }
    // printf("[%s_%d]node->val=%d, *carry=%d\n", __func__, __LINE__, node->val, *carry);
    node->next = AddRecursion(l1, l2, carry);
    if (node->next == NULL) {
        // printf("null readched\n");
        if (*carry) {
            node->next = CreateNewNode();
            if (node->next == NULL) {
                printf("create node erorr\n");
                return NULL;
            }
            node->next->val = *carry;
            // printf("[%s_%d]node->next->val=%d, *carry=%d\n", __func__, __LINE__, node->next->val, *carry);
        }
        return node;
    }
    return node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    if ((l1 == NULL) && (l2 == NULL)) {
        return NULL;
    } else if (l1 == NULL) {
        return l2;
    } else if (l2 == NULL) {
        return l1;
    }
    int carry = 0;
    return AddRecursion(l1, l2, &carry);
}

// @lc code=end

