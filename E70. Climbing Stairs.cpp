// https://leetcode.com/problems/climbing-stairs/description/

// Runtime Beats: 100.00%        Memory Beats: 39.25%

class Solution {
  public:
    int cal(int n, vector<int>& dp) {
        if (n <= 2)
            return n;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = cal(n - 1, dp) + cal(n - 2, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return cal(n, dp);
    }
};