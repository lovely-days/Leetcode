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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || !k)
            return head;

        int size = 1;
        ListNode *node = head;
        while (node->next)
        {
            size++;
            node = node->next;
        }

        node->next = head;
        k = k % size;

        for (int i = 0; i < size - k; i++)
            node = node->next;

        ListNode *result = node->next;
        node->next = nullptr;

        return result;
    }
};
// @lc code=end
