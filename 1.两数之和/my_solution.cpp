/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int num1, num2;
        vector<int> result;

        for (num1 = 0; num1 < nums.size(); num1++)
        {
            for (num2 = num1 + 1; num2 < nums.size(); num2++)
            {
                if (nums[num1] + nums[num2] == target)
                {
                    result.push_back(num1);
                    result.push_back(num2);
                    return result;
                }
            }
        }
        return result;
    }
};
// @lc code=end
