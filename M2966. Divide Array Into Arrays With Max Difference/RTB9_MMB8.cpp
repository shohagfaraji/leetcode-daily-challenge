// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/?envType=daily-question&envId=2025-06-18

// Runtime Beats: 9.57%        Memory Beats: 8.37%

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 2; i < n; i += 3) {
            if (nums[i] - nums[i - 2] > k)
                return {};
            vector<int> temp;
            temp.emplace_back(nums[i - 2]);
            temp.emplace_back(nums[i - 1]);
            temp.emplace_back(nums[i]);
            ans.emplace_back(temp);
        }
        return ans;
    }
};