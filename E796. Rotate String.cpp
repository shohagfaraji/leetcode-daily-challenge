// https://leetcode.com/problems/rotate-string/description/?envType=daily-question&envId=2026-05-03

// Runtime Beats: 100.00%        Memory Beats: 36.38%

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size())
            return false;
        return (s + s).find(goal) != string::npos;
    }
};
