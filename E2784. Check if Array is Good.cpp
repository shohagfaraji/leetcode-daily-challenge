// https://leetcode.com/problems/check-if-array-is-good/description/?envType=daily-question&envId=2026-05-14

// Runtime Beats: 100.00%        Memory Beats: 31.27%

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        vector<int> freq(n + 1, 0);

        for (int i = 0; i < n; i++) {
            if (nums[i] > n)
                return false;
    
            freq[nums[i]]++;
            if (freq[nums[i]] > 1 && nums[i] != n - 1)
                return false;
    
            sum += nums[i];
        }

        n--;

        return sum == (n * (n + 1)) / 2 + n;
    }
};