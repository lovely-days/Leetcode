/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {

        stack<char> stack_ch;
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];

            if (ch == '(' || ch == '[' || ch == '{')
                stack_ch.push(ch);

            else
            {
                if (stack_ch.empty())
                    return 0;

                if (ch == ')' && stack_ch.top() != '(')
                    return 0;

                if (ch == ']' && stack_ch.top() != '[')
                    return 0;

                if (ch == '}' && stack_ch.top() != '{')
                    return 0;

                stack_ch.pop();
            }
        }
        return stack_ch.empty();
    }
};
// @lc code=end
