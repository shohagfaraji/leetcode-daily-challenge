// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/?envType=daily-question&envId=2026-05-23

// Runtime Beats: 100.00%        Memory Beats: 53.59%

class Solution {
public:
    bool check(vector<int>& nums) {
        int breaks = int(nums[nums.size() - 1] > nums[0]);

        for (int i = 1; i < nums.size(); i++)
            breaks += (nums[i - 1] > nums[i]);

        return breaks < 2;
    }
};