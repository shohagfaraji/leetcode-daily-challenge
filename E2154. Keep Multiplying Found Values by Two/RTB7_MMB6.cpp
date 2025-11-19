// https://leetcode.com/problems/keep-multiplying-found-values-by-two/description/?envType=daily-question&envId=2025-11-19

// Runtime Beats: 7.87%        Memory Beats: 6.93%

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int, bool> presentInNums;
        for (int& ele : nums)
            presentInNums[ele] = true;
            
        while (true) {
            if (presentInNums[original])
                original <<= 1;
            else
                break;
        }
        return original;
    }
};