// https://leetcode.com/problems/find-lucky-integer-in-an-array/description/?envType=daily-question&envId=2025-07-05

// Runtime Beats: 100.00%        Memory Beats: 97.53%

class Solution {
public:
    int findLucky(vector<int>& arr) {
        for (int& i : arr) {
            if ((i & 1023) - 1 < arr.size()) {
                arr[(i & 1023) - 1] += (1 << 10);
            }
        }
        for (int i = arr.size() - 1; i >= 0; i--) {
            if ((arr[i] >> 10) == (i + 1)) {
                return (i + 1);
            }
        }
        return -1;
    }
};