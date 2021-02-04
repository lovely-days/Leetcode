/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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

    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || !k)
            return head;

        ListNode *p = head;
        int size = 0;
        while (p) //链表长度
        {
            size++;
            p = p->next;
        }

        k = k % size;

        ListNode *result = head;
        result = reverseBetween(result, 1, size - k);
        result = reverseBetween(result, size - k + 1, size);
        result = reverseBetween(result, 1, size);

        return result;
    }
};
// @lc code=end
