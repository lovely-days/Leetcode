/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *New_Head = new ListNode(-1, head);

        ListNode *slow = New_Head;
        ListNode *fast = New_Head->next;

        while (fast->next)
        {
            if (slow->next->val == fast->next->val)
            {
                ListNode *s = fast;
                fast = fast->next;
                slow->next = fast;
                delete s;
            }
            else
            {
                slow = fast;
                fast = fast->next;
            }
        }
        return New_Head->next;
    }
};
// @lc code=end
