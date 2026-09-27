// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/?envType=daily-question&envId=2026-09-27

// Runtime Beats: 100.00%        Memory Beats: 69.98%

class Solution {
  public:
    string reverseParentheses(string s) {
        stack<int> st;
        int n = s.size();
        vector<int> pair(n, 0);

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                pair[i] = st.top();
                pair[st.top()] = i;
                st.pop();
            }
        }

        string result = "";
        int i = 0, dir = 1;
        while (i >= 0 && i < n) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair[i];
                dir = -dir;
            } else {
                result += s[i];
            }
            i += dir;
        }

        return result;
    }
};