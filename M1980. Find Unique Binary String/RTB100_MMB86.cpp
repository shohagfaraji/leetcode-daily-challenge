// https://leetcode.com/problems/find-unique-binary-string/description/?envType=daily-question&envId=2026-03-08

// Runtime Beats: 100.00%        Memory Beats: 86.66%

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i][i] == '1') {
                ans.push_back('0');
            } else {
                ans.push_back('1');
            }
        }
        return ans;
    }
};
