// https://leetcode.com/problems/mirror-distance-of-an-integer/submissions/1981585372/?envType=daily-question&envId=2026-04-18

// Runtime Beats: 100.00%        Memory Beats: 60.81%

class Solution {
public:
    int mirrorDistance(int n) {
        int temp = n;
        int reverse = 0;

        while (temp > 0) {
            reverse = (reverse * 10) + (temp % 10);
            temp /= 10;
        }

        return abs(n - reverse);
    }
};