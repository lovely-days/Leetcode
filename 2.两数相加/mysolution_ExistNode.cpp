/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *p = l1;
        ListNode *q = l2;

        int carry = 0;

        while (1)
        {
            int value = p->val + q->val + carry;
            carry = value / 10;
            p->val = value % 10;

            if (p->next && q->next)
            {
                p = p->next;
                q = q->next;
            }
            else
                break;
        }

        while (p->next)
        {
            p = p->next;

            int value = p->val + carry;
            p->val = value % 10;
            carry = value / 10;
        }
        while (q->next)
        {
            p->next = q->next;
            p = p->next;
            q = q->next;

            int value = q->val + carry;
            p->val = value % 10;
            carry = value / 10;
        }

        if (carry)
        {
            p->next = new ListNode(carry);
        }

        return l1;
    }
};
// @lc code=end
