// https://leetcode.com/problems/smallest-integer-divisible-by-k/description/?envType=daily-question&envId=2025-11-25

// Runtime Beats: 100.00%        Memory Beats: 52.58%

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k == 1)
            return 1;
        if ((k & 1) == 0 || (k % 5) == 0)
            return -1;
        int r = 0;
        for (int i = 1; i <= k; i++) {
            r = (r * 10 + 1) % k;
            if (r == 0)
                return i;
        }
        return -1;
    }
};
