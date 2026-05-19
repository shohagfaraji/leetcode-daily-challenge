// https://leetcode.com/problems/minimum-common-value/description/?envType=daily-question&envId=2026-05-19

// Runtime Beats: 100.00%        Memory Beats: 58.81%

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j])
                return nums1[i];
            if (nums1[i] < nums2[j])
                i++;
            else
                j++;
        }

        return -1;
    }
};