// https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/?envType=daily-question&envId=2026-05-20

// Runtime Beats: 100.00%        Memory Beats: 99.47%

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> C(A.size());
        long long bitmaskA = 0, bitmaskB = 0;

        for (int i = 0; i < A.size(); i++) {
            bitmaskA |= (1LL << A[i]);
            bitmaskB |= (1LL << B[i]);

            C[i] = __builtin_popcountll(bitmaskA & bitmaskB);
        }

        return C;
    }
};