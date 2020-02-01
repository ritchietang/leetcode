#include <stdio.h>
#include <stdlib.h>

 struct ListNode {
    int val;
    struct ListNode *next;
 };

static struct ListNode * CreateNewNode(void)
{
    struct ListNode * node = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (node == NULL) {
        printf("malloc error\n");
        return NULL;
    }
    return node;
}

extern "C" struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);
#define ARRAY_SIZE(x)       (sizeof(x)/sizeof(x[0]))
int main(int argc, char *argv[])
{
    struct ListNode *l1 = NULL;
    struct ListNode *l2 = NULL;
    struct ListNode *prev, *tmp;
    int array1[] = {9, 9};
    int array2[] = {1};
    unsigned int i;

    for (i = 0; i < ARRAY_SIZE(array1); i++) {
        printf("array1[%d]=%d\n", i, array1[i]);
        tmp =  CreateNewNode();
        if (tmp == NULL) {
            printf("create node erorr\n");
            return -1;
        }
        tmp->val = array1[i];
        if (l1 == NULL) {
            l1 = tmp;
            prev = tmp;
        }
        prev->next = tmp;
        prev = prev->next;
        tmp->next = NULL;
    }

    prev = l2;
    for (i = 0; i < ARRAY_SIZE(array2); i++) {
        printf("array2[%d]=%d\n", i, array2[i]);
        tmp =  CreateNewNode();
        if (tmp == NULL) {
            printf("create node erorr\n");
            return -1;
        }
        tmp->val = array2[i];
        if (l2 == NULL) {
            l2 = tmp;
            prev = tmp;
        }
        prev->next = tmp;
        prev = prev->next;
        tmp->next = NULL;
    }

    tmp = addTwoNumbers(l1, l2);
    while(tmp) {
        printf("val=%d\n", tmp->val);
        tmp = tmp->next;
    }
    return 0;
}
