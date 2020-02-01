#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    if ((nums == NULL) || (numsSize <= 0) || (returnSize == NULL)) {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = 0;
    int *buf = (int *)malloc(sizeof(int) * 2);
    if (buf == NULL) {
        return NULL;
    }
    memset(buf, 0, sizeof(int) * 2);
    if ((numsSize == 1) && (nums[0] == target)) {
        *returnSize = 1;
        buf[0] = nums[0];
        return buf;
    }
    int i, j;
    for (i = 0; i < target - 1; i++) {
        for (j = i + 1; j < target; j ++) {
            if ((nums[i] + nums[j]) == target) {
                buf[0] = i;
                buf[1] = j;
                *returnSize = 2;
                return buf;
            }
        }
    }
    free(buf);
    return NULL;
}