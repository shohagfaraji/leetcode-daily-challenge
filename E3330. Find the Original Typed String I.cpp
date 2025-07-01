// https://leetcode.com/problems/find-the-original-typed-string-i/?envType=daily-question&envId=2025-07-01

// Runtime Beats: 100.00%        Memory Beats: 83.47%

class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int freq = 0;
        int ans = 1;
        for (int i = 1; i < n; i++) {
            if (word[i - 1] != word[i]) {
                ans += freq;
                freq = 0;
            } else {
                freq++;
            }
        }
        ans += freq;
        return ans;
    }
};