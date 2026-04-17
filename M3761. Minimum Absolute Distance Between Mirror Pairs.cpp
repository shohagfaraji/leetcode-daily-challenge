// https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/description/?envType=daily-question&envId=2026-04-17

// Runtime Beats: 70.34%        Memory Beats: 90.69%

class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int minDis = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) != mp.end())
                minDis = min(minDis, i - mp[nums[i]]);

            int revInt = 0;
            while (nums[i] > 0) {
                revInt *= 10;
                revInt += (nums[i] % 10);
                nums[i] /= 10;
            }
            mp[revInt] = i;
        }

        return (minDis != INT_MAX ? minDis : -1);
    }
};