// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/?envType=daily-question&envId=2025-06-29

// Runtime Beats: 84.84%        Memory Beats: 34.63%

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int mod = 1e9 + 7;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> pw(n, 1);
        for (int i = 1; i < n; i++)
            pw[i] = (pw[i - 1] << 1) % mod;
        int l = 0, r = n - 1;
        int ans = 0;
        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                ans = (ans + pw[r - l]) % mod;
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
};
