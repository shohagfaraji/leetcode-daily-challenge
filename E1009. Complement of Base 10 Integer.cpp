// https://leetcode.com/problems/complement-of-base-10-integer/description/?envType=daily-question&envId=2026-03-11

// Runtime Beats: 100.00%        Memory Beats: 59.24%

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0)
            return 1;
        int setbit = 1;
        int complement = 0;
        while (n > 0) {
            if ((n & 1) == 0)
                complement += setbit;
            n >>= 1;
            setbit <<= 1;
        }
        return complement;
    }
};
