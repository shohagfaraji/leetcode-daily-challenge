// https:leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/description/?envType=daily-question&envId=2025-06-28

// Runtime Beats: 100.00%        Memory Beats: 78.54%

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> indx(n);
        for (int i = 0; i < n; i++)
            indx[i] = {nums[i], i};

        nth_element(indx.begin(), indx.begin() + k, indx.end(),
                    greater<pair<int, int>>());

        bitset<1000> take = 0;
        for (int i = 0; i < k; i++)
            take[indx[i].second] = 1;

        vector<int> ans(k);
        for (int i = 0, j = 0; i < 1000; i++) {
            if (take[i]) {
                ans[j] = nums[i];
                j++;
            }
        }
        return ans;
    }
};
