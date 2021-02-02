/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *New_Head = new ListNode(-1, head);
        ListNode *p = New_Head;

        while (p->next && p->next->next)
        {
            ListNode *s = p->next;
            p->next = s->next;
            s->next = p->next->next;
            p->next->next = s;
            p = s;
        }
        return New_Head->next;
    }
};
// @lc code=end
