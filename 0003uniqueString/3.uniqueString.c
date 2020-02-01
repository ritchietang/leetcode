/*
 * @lc app=leetcode.cn id=3 lang=c
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE(x)           (sizeof(x)/sizeof(x[0]))
#define MAX(x, y)               ((x) > (y) ? (x) : (y))

int isAlpha(char ch)
{
    if (((ch >= 'a') && (ch <= 'z')) || ((ch >= 'A') && (ch <= 'Z'))) {
        return 1;
    } else {
        return 0;
    }
}

int lengthOfLongestSubstring(char * s)
{
    int mapChar[128];
    int count = 0;
    int maxCount = 0;
    int offset, start;
    int i;
    if (s == NULL) {
        return 0;
    }
    memset(mapChar, -1, sizeof(mapChar));
    // printf("s=%s\n", s);
    for (offset = 0, start = 0; *(s + offset) != '\0'; offset++) {
        if (mapChar[s[offset]] == -1) {
            mapChar[s[offset]] = offset;
        } else {
            start = mapChar[s[offset]] + 1;
            memset(mapChar, -1, sizeof(mapChar));
            for (i = start; i <= offset; i++) {
                mapChar[s[i]] = i;
                // printf("%c ", s[i]);
            }
            // printf("\n");
        }
        maxCount = MAX(maxCount, (offset - start + 1));
        // printf("------------offset=%d, start=%d, maxCount=%d\n", offset, start, maxCount);

    }
    return maxCount;
}


// @lc code=end

