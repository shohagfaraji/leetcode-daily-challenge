// https://leetcode.com/problems/find-the-largest-almost-missing-integer/description/?envType=daily-question&envId=2026-08-18

// Runtime Beats: 100.00%        Memory Beats: 78.95%

class Solution {
  public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> f(51, 0);
        for (int& ele : nums)
            f[ele]++;

        int ans = -1;
        for (int i = 0; i < n; i++) {
            if ((k == n) ||
                ((f[nums[i]] == 1) && (k == 1 || i == 0 || i == n - 1)))
                ans = max(ans, nums[i]);
        }

        return ans;
    }
};
