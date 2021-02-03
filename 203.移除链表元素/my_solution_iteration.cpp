/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *New_Head = new ListNode(-1, head);
        ListNode *p = New_Head;

        while (p->next)
        {
            if (p->next->val == val)
            {
                ListNode *s = p->next;
                p->next = s->next;
                delete s;
            }
            else
                p = p->next;
        }

        return New_Head->next;
    }
};
// @lc code=end
