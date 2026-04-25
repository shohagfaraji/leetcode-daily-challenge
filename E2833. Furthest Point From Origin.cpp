// https://leetcode.com/problems/furthest-point-from-origin/?envType=daily-question&envId=2026-04-24

// Runtime Beats: 100.00%        Memory Beats: 65.09%

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int leftCount = 0;
        int rightCount = 0;

        for (char& move : moves) {
            if (move == 'L')
                leftCount++;
            else if (move == 'R')
                rightCount++;
        }

        if (leftCount > rightCount)
            return (moves.size() - 2 * rightCount);

        return (moves.size() - 2 * leftCount);
    }
};