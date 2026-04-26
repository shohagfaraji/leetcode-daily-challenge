// https://leetcode.com/problems/detect-cycles-in-2d-grid/description/?envType=daily-question&envId=2026-04-26

// Runtime Beats: 91.64%        Memory Beats: 84.38%

class Solution {
public:
    int row, col;
    bitset<500> vis[500];

    bool isValid(int i, int j) {
        return i >= 0 && i < row && j >= 0 && j < col;
    }

    void dfs(vector<vector<char>>& grid, int i, int j, int parI, int parJ,
             bool& cycle) {
        vis[i][j] = 1;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for (int d = 0; d < 4 && !cycle; d++) {
            int ni = i + dx[d];
            int nj = j + dy[d];

            if (!isValid(ni, nj) || grid[ni][nj] != grid[i][j])
                continue;

            if (!vis[ni][nj]) {
                dfs(grid, ni, nj, i, j, cycle);
            } else if (ni != parI || nj != parJ) {
                cycle = true;
                return;
            }
        }
    }

    bool containsCycle(vector<vector<char>>& grid) {
        row = grid.size();
        col = grid[0].size();

        for (int i = 0; i < 500; i++)
            vis[i].reset();

        bool cycle = false;

        for (int i = 0; i < row && !cycle; i++) {
            for (int j = 0; j < col && !cycle; j++) {
                if (!vis[i][j]) {
                    dfs(grid, i, j, -1, -1, cycle);
                }
            }
        }

        return cycle;
    }
};