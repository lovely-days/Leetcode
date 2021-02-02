/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1 && !l2)
            return nullptr;
        else if (!l1)
            return l2;
        else if (!l2)
            return l1;

        ListNode *New_Head = new ListNode(-1, l1);
        ListNode *p = New_Head;
        ListNode *q = l2;

        while (p->next && q)
        {
            if (p->next->val > q->val)
            {
                ListNode *s = new ListNode(q->val);
                s->next = p->next;
                p->next = s;
                q = q->next;
            }
            else
                p = p->next;
        }

        while (q)
        {
            p->next = new ListNode(q->val);
            q = q->next;
            p = p->next;
        }

        return New_Head->next;
    }
};
// @lc code=end
