// https://leetcode.com/problems/finding-pairs-with-a-certain-sum/description/?envType=daily-question&envId=2025-07-06

// Runtime Beats: 65.55%        Memory Beats: 54.91%

class FindSumPairs {
private:
    vector<int> n1, n2;
    unordered_map<int, int> m;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        for (int& val : nums2) {
            m[val]++;
        }
    }

    void add(int index, int val) {
        m[n2[index]]--;
        n2[index] += val;
        m[n2[index]]++;
    }

    int count(int tot) {
        int ans = 0;
        for (int& val : n1) {
            if (m.count(tot - val)) {
                ans += m[tot - val];
            }
        }
        return ans;
    }
};