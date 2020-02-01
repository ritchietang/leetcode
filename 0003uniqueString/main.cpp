#include "iostream"
using namespace std;

extern "C" int lengthOfLongestSubstring(char * s);
int main(int argc, char *argv[])
{
    char *str0 = "abcabcbb";
    char *str1 = "au";
    char *str2 = "pwwkew";
    // char *str3 = "dvdf";
    char *str3 = "aabaab!bb";

    int ret;
    ret = lengthOfLongestSubstring(str0);
    std::cout<<"ret="<<ret<<std::endl;

    ret = lengthOfLongestSubstring(str1);
    std::cout<<"ret="<<ret<<std::endl;

    ret = lengthOfLongestSubstring(str2);
    std::cout<<"ret="<<ret<<std::endl;

    ret = lengthOfLongestSubstring(str3);
    std::cout<<"ret="<<ret<<std::endl;
    return 0;
}