// https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/description/?envType=daily-question&envId=2026-09-26

// Runtime Beats: 87.85%        Memory Beats: 66.67%

class Solution {
  public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> knowledgeMap;

        for (int i = 0; i < knowledge.size(); i++) {
            knowledgeMap[knowledge[i][0]] = knowledge[i][1];
        }

        int n = s.size();
        string result = "", key = "";

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                i++;
                while (i < n && s[i] != ')') {
                    key.push_back(s[i]);
                    i++;
                }

                result += knowledgeMap.count(key) ? knowledgeMap[key] : "?";
                key = "";
                continue;
            }

            result.push_back(s[i]);
        }

        return result;
    }
};