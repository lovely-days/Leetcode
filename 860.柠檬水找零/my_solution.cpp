/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five_size = 0;
        int ten_size = 0;
        int twenty_size = 0;

        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5)
            {
                five_size++;
            }
            else if (bills[i] == 10)
            {
                if (five_size != 0)
                {
                    five_size--;
                    ten_size++;
                }
                else
                {
                    return 0;
                }
            }
            else if (bills[i] == 20)
            {
                if (ten_size != 0)
                {
                    if (five_size != 0)
                    {
                        ten_size--;
                        five_size--;
                        twenty_size++;
                    }
                    else
                    {
                        return 0;
                    }
                }
                else if (five_size > 3)
                {
                    five_size -= 3;
                    twenty_size++;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }

        return 1;
    }
};
// @lc code=end
