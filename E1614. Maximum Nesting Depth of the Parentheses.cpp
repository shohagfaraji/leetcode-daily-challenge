// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/?envType=daily-question&envId=2026-09-28

// Runtime Beats: 100.00%        Memory Beats: 98.98%

class Solution {
  public:
    int maxDepth(string s) {
        int ans = 0, cnt = 0;

        for (char& c : s) {
            if (c == '(') {
                cnt++;
                ans = max(ans, cnt);
            } else if (c == ')') {
                cnt--;
            }
        }

        return ans;
    }
};