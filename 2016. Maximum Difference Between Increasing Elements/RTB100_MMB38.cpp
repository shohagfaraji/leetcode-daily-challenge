// https://leetcode.com/problems/maximum-difference-between-increasing-elements/?envType=daily-question&envId=2025-06-16

// Runtime Beats: 100.00%        Memory Beats: 38.11%

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mn = nums[0], ans = -1, n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] < mn) {
                mn = nums[i];
            } else {
                ans = max(ans, nums[i] - mn);
            }
        }
        return (ans <= 0 ? -1 : ans);
    }
};