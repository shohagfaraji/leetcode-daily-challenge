// https://leetcode.com/problems/find-unique-binary-string/description/?envType=daily-question&envId=2026-03-08

// Runtime Beats: 100.00%        Memory Beats: 42.82%

class Solution {
public:
    int binToDec(string& s) {
        int dec = 0;
        for (char c : s)
            dec = (dec << 1) + (c - '0');
        return dec;
    }

    void decToBin(int num, string& ret) {
        while (num > 0) {
            if (num & 1) {
                ret = "1" + ret;
            } else {
                ret = "0" + ret;
            }
            num >>= 1;
        }
    }

    string findDifferentBinaryString(vector<string>& nums) {
        sort(nums.begin(), nums.end());

        if (nums[0] != string(nums[0].size(), '0'))
            return string(nums[0].size(), '0');

        if (nums.back() != string(nums[0].size(), '1'))
            return string(nums[0].size(), '1');

        string ret = "";
        int prevNum = binToDec(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            int currNum = binToDec(nums[i]);
            if (currNum - prevNum > 1) {
                prevNum++;
                decToBin(prevNum, ret);
                break;
            }
            prevNum = currNum;
        }

        while (ret.size() < nums[0].size())
            ret = "0" + ret;

        return ret;
    }
};
