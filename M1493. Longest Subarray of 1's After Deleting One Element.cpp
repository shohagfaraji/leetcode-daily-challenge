// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/?envType=daily-question&envId=2025-08-24

// Runtime Beats: 100.00%        Memory Beats: 5.09%

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int oneCount = 0;
        vector<int> l(n);
        for (int i = 0; i < n; i++) {
            if (nums[i]) {
                oneCount++;
            } else {
                oneCount = 0;
            }
            l[i] = oneCount;
        }
        oneCount = 0;
        vector<int> r(n);
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i]) {
                oneCount++;
            } else {
                oneCount = 0;
            }
            r[i] = oneCount;
        }
        int ans = 0;
        if (n > 1)
            ans = max(l[n - 2], r[1]);
        for (int i = 1; i + 1 < n; i++)
            ans = max(ans, l[i - 1] + r[i + 1]);
        return ans;
    }
};