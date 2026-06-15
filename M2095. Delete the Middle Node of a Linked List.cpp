// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/?envType=daily-question&envId=2026-06-15

// Runtime Beats: 100.00%        Memory Beats: 54.78%

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
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == nullptr)
            return NULL;

        ListNode* left = head;
        ListNode* middle = head;
        ListNode* right = head->next;

        while (right != nullptr) {
            left = middle;
            middle = middle->next;
            right = right->next;

            if (right)
                right = right->next;
        }

        left->next = middle->next;

        return head;
    }
};