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

        ListNode *p = new ListNode();

        if (l1->val > l2->val)
        {
            p->val = l2->val;
            p->next = mergeTwoLists(l1, l2->next);
        }
        else
        {
            p->val = l1->val;
            p->next = mergeTwoLists(l1->next, l2);
        }

        return p;
    }
};
// @lc code=end
