// https://leetcode.com/problems/maximum-difference-between-increasing-elements/?envType=daily-question&envId=2025-06-16

// Runtime Beats: 100.00%        Memory Beats: 5.67%

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int i = 0, ans = -1, n = nums.size();
        vector<int> Min(n), Max(n);
        Min[0] = nums[0];
        Max[n - 1] = nums[n - 1];
        for (i = 1; i < n; i++)
            Min[i] = min(Min[i - 1], nums[i]);
        for (i = n - 2; i >= 0; i--)
            Max[i] = max(Max[i + 1], nums[i]);
        for (i = 0; i < n; i++)
            ans = max(ans, Max[i] - Min[i]);
        return (ans <= 0 ? -1 : ans);
    }
};