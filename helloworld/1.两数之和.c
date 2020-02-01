/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 *
 * https://leetcode-cn.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (47.43%)
 * Likes:    7547
 * Dislikes: 0
 * Total Accepted:    801K
 * Total Submissions: 1.7M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 * 
 * 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
 * 
 * 示例:
 * 
 * 给定 nums = [2, 7, 11, 15], target = 9
 * 
 * 因为 nums[0] + nums[1] = 2 + 7 = 9
 * 所以返回 [0, 1]
 * 
 * 
 */

// @lc code=start

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    for (i = 0; i < numsSize - 1; i++) {
        for (j = i + 1; j < numsSize; j ++) {
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


// @lc code=end

