// https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/description/?envType=daily-question&envId=2025-11-26

// Runtime Beats: 68.96%        Memory Beats: 78.67%

class Solution {
private:
    static const int mod = 1000000007;

public:
    int numberOfPaths(vector<vector<int>>& grid, int K) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(K, 0)));

        const int g00 = grid[0][0];

        for (int k = 0; k < K; k++)
            if ((g00 + k) % K == 0)
                dp[0][0][k] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                const int gij = grid[i][j];
                for (int k = 0; k < K; k++) {
                    const int nk = (k + gij) % K;
                    if (i > 0)
                        dp[i][j][k] = dp[i - 1][j][nk];
                    if (j > 0)
                        dp[i][j][k] += dp[i][j - 1][nk];
                    dp[i][j][k] %= mod;
                }
            }
        }
        return dp[n - 1][m - 1][0];
    }
};