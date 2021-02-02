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
        ListNode *result = new ListNode(0, NULL);
        ListNode *p = l1;
        ListNode *q = l2;
        ListNode *r = result;

        int carry = 0; //进位标识

        while (1) //重合部分
        {
            int value = p->val + q->val + carry;
            carry = value / 10;
            r->val = value % 10;

            if (p->next && q->next)
            {
                r->next = new ListNode(0);
                r = r->next;
                p = p->next;
                q = q->next;
            }
            else
                break;
        }

        while (p->next) // l1.size > l2.size
        {
            r->next = new ListNode(0);
            r = r->next;
            p = p->next;

            int value = p->val + carry;
            r->val = value % 10;
            carry = value / 10;
        }
        while (q->next) // l2.size > l1.size
        {
            r->next = new ListNode(0);
            r = r->next;
            q = q->next;

            int value = q->val + carry;
            r->val = value % 10;
            carry = value / 10;
        }

        if (carry) //最后进位
        {
            r->next = new ListNode(carry);
        }

        return result;
    }
};
// @lc code=end
