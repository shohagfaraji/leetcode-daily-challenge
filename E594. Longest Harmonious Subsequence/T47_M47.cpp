// https://leetcode.com/problems/longest-harmonious-subsequence/description/?envType=daily-question&envId=2025-06-30

// Runtime Beats: 47.48%        Memory Beats: 47.36%

class Solution {
public:
    int findLHS(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        unordered_map<int, int> mp;
        for (int& i : nums)
            mp[i]++;
        if (mp.size() == 1)
            return 0;
        int ans = 0;
        for (auto& [val, frq] : mp) {
            if (mp.count(val - 1)) {
                ans = max(ans, frq + mp[val - 1]);
            }
        }
        return ans;
    }
};