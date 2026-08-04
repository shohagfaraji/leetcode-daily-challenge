// https://leetcode.com/problems/find-missing-elements/description/?envType=daily-question&envId=2026-08-04

// Runtime Beats: 100.00%        Memory Beats: 54.61%

class Solution {
  public:
    vector<int> findMissingElements(vector<int>& nums) {
        bitset<101> has = 0;
        int mn = 131, mx = -1;

        for (int& e : nums) {
            has[e] = 1;
            mn = min(mn, e);
            mx = max(mx, e);
        }

        vector<int> ans;
        
        for (int i = mn + 1; i < mx; i++) {
            if (!has[i])
                ans.emplace_back(i);
        }

        return ans;
    }
};