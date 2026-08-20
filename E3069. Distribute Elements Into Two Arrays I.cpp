// https://leetcode.com/problems/distribute-elements-into-two-arrays-i/description/?envType=daily-question&envId=2026-08-20

// Runtime Beats: 100.00%        Memory Beats: 97.12%

class Solution {
  public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1, arr2;
        arr1.emplace_back(nums[0]);
        arr2.emplace_back(nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            if (arr1.back() > arr2.back()) {
                arr1.emplace_back(nums[i]);
            } else {
                arr2.emplace_back(nums[i]);
            }
        }

        arr1.insert(arr1.end(), arr2.begin(), arr2.end());

        return arr1;
    }
};
