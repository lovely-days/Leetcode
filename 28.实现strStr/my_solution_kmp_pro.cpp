/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    void next_val(string needle, vector<int> &next)
    {
        if (!next.empty())
            next.clear();

        next.resize(needle.size() + 1);

        next[0] = -1;
        next[1] = 0;

        int i = 1, j = 0;
        while (i < needle.size())
        {
            if (j == -1 || needle[i] == needle[j])
            {
                i++;
                j++;
                if (needle[i] != needle[j])
                    next[i] = j;
                else
                    next[i] = next[j];
            }
            else
            {
                j = next[j];
            }
        }
    }

    int strStr(string haystack, string needle)
    {
        if (needle.empty())
            return 0;
        if (haystack.size() < needle.size())
            return -1;

        vector<int> next;
        next_val(needle, next);

        //size_type 至 int 类型间转换，否则与 -1 比较时出错
        int size1 = haystack.size();
        int size2 = needle.size();

        int i = 0, j = 0;
        while (i < size1 && j < size2)
        {
            if (j == -1 || haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else
            {
                j = next[j];
            }
        }

        if (j == needle.size())
            return i - j;
        else
            return -1;
    }
};
// @lc code=end
