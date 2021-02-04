/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
        ListNode *end = New_Head;

        for (int i = 1; i < m; i++)
            front = front->next;

        for (int i = 0; i < n; i++)
            end = end->next;

        for (int i = 0; i < n - m; i++)
        {
            ListNode *s = front->next;
            front->next = s->next;
            s->next = end->next;
            end->next = s;
        }

        return New_Head->next;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *p = head;
        int size = 0;
        while (p) //链表长度
        {
            size++;
            p = p->next;
        }

        int num = size / k;
        ListNode *m = head;

        for (int i = 0; i < num; i++) //分组逆转
        {
            m = reverseBetween(m, k * i + 1, k * (i + 1));
        }

        return m;
        ;
    }
};
// @lc code=end
