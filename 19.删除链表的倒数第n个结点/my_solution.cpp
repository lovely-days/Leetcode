/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head)
            return nullptr;

        ListNode *New_Head = new ListNode(-1, head);

        ListNode *left = New_Head;
        ListNode *right = New_Head;

        for (int i = 0; i < n; i++)
        {
            if (right->next)
                right = right->next;
            else
                return nullptr;
        }

        while (right->next)
        {
            left = left->next;
            right = right->next;
        }

        ListNode *s = left->next;
        left->next = left->next->next;
        delete s;

        return New_Head->next;
    }
};
// @lc code=end
