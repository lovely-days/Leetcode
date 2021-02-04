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
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        ListNode *New_Head = new ListNode(-1, head);
        ListNode *front = New_Head;

        for (int i = 1; i < m; i++)
            front = front->next;

        ListNode *r = front->next;

        for (int i = 0; i < n - m; i++)
        {
            ListNode *s = front->next;
            front->next = r->next;   //将 r 后结点插入至 front结点后
            r->next = r->next->next; //更新 r后结点
            front->next->next = s;
        }

        return New_Head->next;
    }
};
// @lc code=end
