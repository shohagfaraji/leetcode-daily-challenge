// https://leetcode.com/problems/2-keys-keyboard/description/

// Runtime Beats: 100.00%        Memory Beats: 78.34%

class Solution {
  public:
    int minSteps(int n) {
        int ans = 0, i = 2;

        while (n > 1) {
            if (n % i) {
                i++;
                continue;
            }
            ans += i;
            n /= i;
        }

        return ans;
    }
};