// https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/description/?envType=daily-question&envId=2026-04-27

// Runtime Beats: 72.58%        Memory Beats: 61.29%

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        // directions: left, right, up, down
        vector<vector<vector<int>>> dirs = {
            {},
            {{0, -1}, {0, 1}},  // 1
            {{-1, 0}, {1, 0}},  // 2
            {{0, -1}, {1, 0}},  // 3
            {{0, 1}, {1, 0}},   // 4
            {{0, -1}, {-1, 0}}, // 5
            {{0, 1}, {-1, 0}}   // 6
        };

        // check if neighbor connects back
        auto isConnected = [&](int x, int y, int nx, int ny) {
            for (auto& d : dirs[grid[nx][ny]]) {
                if (nx + d[0] == x && ny + d[1] == y)
                    return true;
            }
            return false;
        };

        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        q.push({0, 0});
        vis[0][0] = true;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == n - 1 && y == m - 1)
                return true;

            for (auto& d : dirs[grid[x][y]]) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
                    if (isConnected(x, y, nx, ny)) {
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return false;
    }
};