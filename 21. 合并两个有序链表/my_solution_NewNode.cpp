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
/*
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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

        ListNode *result = new ListNode();

        ListNode *p = l1;
        ListNode *q = l2;
        ListNode *r = result;

        while (p && q)
        {
            if (p->val > q->val)
            {
                r->next = new ListNode(q->val);
                r = r->next;
                q = q->next;
            }
            else
            {
                r->next = new ListNode(p->val);
                r = r->next;
                p = p->next;
            }
        }

        while (p)
        {
            r->next = new ListNode(p->val);
            p = p->next;
            r = r->next;
        }
        while (q)
        {
            r->next = new ListNode(q->val);
            q = q->next;
            r = r->next;
        }

        return result->next;
    }
};
// @lc code=end
