/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *result = new ListNode();
        ListNode *New_Head = new ListNode(-1, head);

        while (New_Head->next)
        {
            ListNode *h = New_Head->next;
            New_Head->next = h->next;

            h->next = result->next;
            result->next = h;
        }
        return result->next;
    }
};
// @lc code=end
