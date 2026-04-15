// https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/description/?envType=daily-question&envId=2026-04-15

// Runtime Beats: 100.00%        Memory Beats: 37.22%

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        if (words[startIndex] == target)
            return 0;

        int n = words.size();
        int left = (startIndex - 1 + n) % n;
        int right = (startIndex + 1) % n;

        while (left != right) {
            if (words[left] == target)
                return (startIndex - left + n) % n;

            if (words[right] == target)
                return (right - startIndex + n) % n;

            left--, right++;
            if (left < 0)
                left = n - 1;
            if (right == n)
                right = 0;
        }

        if (words[left] == target)
            return (startIndex - left + n) % n;

        if (words[right] == target)
            return (right - startIndex + n) % n;

        return -1;
    }
};
