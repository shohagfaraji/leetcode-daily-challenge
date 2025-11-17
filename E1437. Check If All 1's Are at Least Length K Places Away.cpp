// https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/description/?envType=daily-question&envId=2025-11-17

// Runtime Beats: 100.00%        Memory Beats: 74.91%

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        k++;
        int lastOne = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                if (lastOne == -1) {
                    lastOne = i;
                    continue;
                }
                if (i - lastOne < k) {
                    return false;
                } else {
                    lastOne = i;
                }
            }
        }
        return true;
    }
};