// https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/description/?envType=daily-question&envId=2025-11-27

// Runtime Beats: 100.00%        Memory Beats: 78.84%

class Solution {
public:
    using ll = long long;

    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> minSum(k, LLONG_MAX >> 1);
        ll prefSum = 0;
        ll ans = LLONG_MIN;
        minSum[k - 1] = 0;
        for (int i = 0; i < n; i++) {
            prefSum += nums[i];
            ll& kSum = minSum[i % k];
            ans = max(ans, prefSum - kSum);
            kSum = min(kSum, prefSum);
        }
        return ans;
    }
};