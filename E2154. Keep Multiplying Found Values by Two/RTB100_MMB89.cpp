// https://leetcode.com/problems/keep-multiplying-found-values-by-two/description/?envType=daily-question&envId=2025-11-19

// Runtime Beats: 100.00%        Memory Beats: 89.20%

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int bits = 0;
        for (auto& ele : nums) {
            if (ele % original != 0)
                continue;
            ele = ele / original;
            if ((ele & (ele - 1)) == 0)
                bits |= ele;
        }
        int x = bits + 1;
        return original * (x & -x);
    }
};