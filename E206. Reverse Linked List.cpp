// https://leetcode.com/problems/reverse-linked-list/description/

// Runtime Beats: 100.00%        Memory Beats: 40.89%

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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* newHead = reverseList(head->next);

        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
};
