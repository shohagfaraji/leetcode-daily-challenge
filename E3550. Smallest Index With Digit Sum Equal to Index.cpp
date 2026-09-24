// https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/description/?envType=daily-question&envId=2026-09-24

// Runtime Beats: 100.00%        Memory Beats: 52.36%

class Solution {
  public:
    int smallestIndex(vector<int>& nums) {
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] > 0) {
                sum += (nums[i] % 10);
                nums[i] /= 10;
            }

            if (sum == i)
                return i;

            sum = 0;
        }

        return -1;
    }
};