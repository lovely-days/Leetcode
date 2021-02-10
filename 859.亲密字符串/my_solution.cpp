/*
 * @lc app=leetcode.cn id=859 lang=cpp
 *
 * [859] 亲密字符串
 */

#include <string>
#include <queue>
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool buddyStrings(string A, string B)
    {
        if (A.size() != B.size())
            return 0;

        /*if (A == B)
        {
            if (A.size() == 1)
                return false;

            sort(A.begin(), A.end());
            auto ptr = unique(A.begin(), A.end());

            if (ptr == A.end())
                return false;
            else
                return true;
        }*/

        if (A == B)
        {
            vector<int> count(26, 0);

            for (int i = 0; i < A.size(); i++)
            {
                count[A[i] - 'a']++;
            }
            for (int i = 0; i < count.size(); i++)
            {
                if (count[i] > 1)
                    return 1;
            }
            return 0;
        }

        vector<char> vec_ch;

        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] != B[i])
            {

                vec_ch.push_back(A[i]);
                vec_ch.push_back(B[i]);
            }
        }

        if (vec_ch.size() == 4)
        {
            return vec_ch[0] == vec_ch[3] && vec_ch[1] == vec_ch[2];
        }

        return 0;
    }
};
// @lc code=end
