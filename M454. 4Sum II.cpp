// https://leetcode.com/problems/4sum-ii/description/

// Runtime Beats: 72.55%        Memory Beats: 10.10%

class Solution {
  public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        unordered_map<int, int> ab;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ab[nums1[i] + nums2[j]]++;
            }
        }

        unordered_map<int, int> cd;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cd[nums3[i] + nums4[j]]++;
            }
        }

        int ans = 0;
        for (auto& [sum, cnt] : ab) {
            if (cd.count(-sum)) {
                ans += (cd[-sum] * cnt);
            }
        }

        return ans;
    }
};