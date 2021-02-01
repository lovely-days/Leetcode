/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start

#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> um;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++)
        {
            if (um.find(target - nums[i]) != um.end())
            {
                result.push_back(um[target - nums[i]]);
                result.push_back(i);
                return result;
            }
            um[nums[i]] = i;
        }
        return result;
    }
};
// @lc code=end
