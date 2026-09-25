// https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

// Runtime Beats: 100.00%        Memory Beats: 33.83%

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return head;

        ListNode* prev = head;
        ListNode* curr = prev->next;

        while (curr != nullptr) {
            if (curr->val == prev->val) {
                if (curr->next)
                    prev->next = curr->next;
                else
                    prev->next = nullptr;
            } else {
                prev = curr;
            }
            curr = prev->next;
        }

        return head;
    }
};