// https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/description/?envType=daily-question&envId=2025-11-29

// Runtime Beats: 100.00%        Memory Beats: 69.81%

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        for (int& i : nums)
            sum += i;
        return (sum % k);
    }
};