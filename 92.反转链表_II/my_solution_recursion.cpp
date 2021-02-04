/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
    ListNode *end_next;

    ListNode *reverse(ListNode *head, int end)
    {
        if (end == 1)
        {
            end_next = head->next;
            return head;
        }
        else
        {
            ListNode *p = reverse(head->next, end - 1);
            head->next->next = head;
            head->next = end_next;
            return p;
        }
    }

    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        if (m == 1)
            return reverse(head, n);
        else
        {
            head->next = reverseBetween(head->next, m - 1, n - 1);
            return head;
        }
    }
};
// @lc code=end
