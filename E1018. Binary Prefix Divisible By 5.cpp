// https://leetcode.com/problems/binary-prefix-divisible-by-5/description/?envType=daily-question&envId=2025-11-24

// Runtime Beats: 100.00%        Memory Beats: 94.87%

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int mask = 0;
        vector<bool> ans;
        for (int& ele : nums) {
            mask = ((mask << 1) + ele) % 5;
            ans.emplace_back(mask == 0);
        }
        return ans;
    }
};