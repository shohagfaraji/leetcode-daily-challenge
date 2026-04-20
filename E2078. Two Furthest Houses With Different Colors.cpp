// https://leetcode.com/problems/two-furthest-houses-with-different-colors/description/?envType=daily-question&envId=2026-04-20

// Runtime Beats: 100.00%        Memory Beats: 72.82%

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int mxDis = 0;

        for (int i = 0; i < colors.size(); i++) {
            if (colors[i] != colors[0] ||
                colors[colors.size() - i - 1] != colors[colors.size() - 1])
                mxDis = max(mxDis, i);
        }

        return mxDis;
    }
};