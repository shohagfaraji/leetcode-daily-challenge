// https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/description/?envType=daily-question&envId=2025-06-14

// Runtime Beats: 100.00%        Memory Beats: 99.25%

class Solution {
public:
    int minMaxDifference(int num) {
        int firstNon9Digit = -1;
        int temp = num;
        while (temp > 0) {
            int r = temp % 10;
            if (r != 9)
                firstNon9Digit = r;
            temp /= 10;
        }
        temp = num;
        int max = 0, i = 1;
        while (temp > 0) {
            int d = temp % 10;
            if (d == firstNon9Digit) {
                max += (i * 9);
            } else {
                max += (i * d);
            }
            temp /= 10;
            i *= 10;
        }
        i = 1, temp = num;
        int min = 0, firstDigit = -1;
        while (temp > 0) {
            int r = temp % 10;
            firstDigit = r;
            temp /= 10;
        }
        temp = num;
        while (temp > 0) {
            int d = temp % 10;
            if (d != firstDigit)
                min += (i * d);
            i *= 10;
            temp /= 10;
        }
        return (max - min);
    }
};