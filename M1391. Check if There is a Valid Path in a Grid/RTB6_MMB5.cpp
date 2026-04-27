// https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/description/?envType=daily-question&envId=2026-04-27

// Runtime Beats: 6.05%        Memory Beats: 5.24%

class Solution {
public:
    int n, m;
    vector<vector<bool>> vis;

    bool isValid(int i, int j) { return (i >= 0 && i < n && j >= 0 && j < m); }

    bool func(vector<vector<int>>& grid, int x, int y) {
        if (x == n - 1 && y == m - 1)
            return true;

        vis[x][y] = true;
        bool isPossible = false;

        if (grid[x][y] == 1) {
            // left
            if (isValid(x, y - 1) && !vis[x][y - 1])
                if (grid[x][y - 1] == 1 || grid[x][y - 1] == 4 ||
                    grid[x][y - 1] == 6)
                    isPossible |= func(grid, x, y - 1);

            // right
            if (isValid(x, y + 1) && !vis[x][y + 1])
                if (grid[x][y + 1] == 1 || grid[x][y + 1] == 3 ||
                    grid[x][y + 1] == 5)
                    isPossible |= func(grid, x, y + 1);

        } else if (grid[x][y] == 2) {
            // up
            if (isValid(x - 1, y) && !vis[x - 1][y])
                if (grid[x - 1][y] == 2 || grid[x - 1][y] == 3 ||
                    grid[x - 1][y] == 4)
                    isPossible |= func(grid, x - 1, y);

            // down
            if (isValid(x + 1, y) && !vis[x + 1][y])
                if (grid[x + 1][y] == 2 || grid[x + 1][y] == 5 ||
                    grid[x + 1][y] == 6)
                    isPossible |= func(grid, x + 1, y);

        } else if (grid[x][y] == 3) {
            // left
            if (isValid(x, y - 1) && !vis[x][y - 1])
                if (grid[x][y - 1] == 1 || grid[x][y - 1] == 4 ||
                    grid[x][y - 1] == 6)
                    isPossible |= func(grid, x, y - 1);

            // down
            if (isValid(x + 1, y) && !vis[x + 1][y])
                if (grid[x + 1][y] == 2 || grid[x + 1][y] == 5 ||
                    grid[x + 1][y] == 6)
                    isPossible |= func(grid, x + 1, y);

        } else if (grid[x][y] == 4) {
            // down
            if (isValid(x + 1, y) && !vis[x + 1][y])
                if (grid[x + 1][y] == 2 || grid[x + 1][y] == 5 ||
                    grid[x + 1][y] == 6)
                    isPossible |= func(grid, x + 1, y);

            // right
            if (isValid(x, y + 1) && !vis[x][y + 1])
                if (grid[x][y + 1] == 1 || grid[x][y + 1] == 3 ||
                    grid[x][y + 1] == 5)
                    isPossible |= func(grid, x, y + 1);

        } else if (grid[x][y] == 5) {
            // up
            if (isValid(x - 1, y) && !vis[x - 1][y])
                if (grid[x - 1][y] == 2 || grid[x - 1][y] == 3 ||
                    grid[x - 1][y] == 4)
                    isPossible |= func(grid, x - 1, y);

            // left
            if (isValid(x, y - 1) && !vis[x][y - 1])
                if (grid[x][y - 1] == 1 || grid[x][y - 1] == 4 ||
                    grid[x][y - 1] == 6)
                    isPossible |= func(grid, x, y - 1);

        } else { // type 6
            // up
            if (isValid(x - 1, y) && !vis[x - 1][y])
                if (grid[x - 1][y] == 2 || grid[x - 1][y] == 3 ||
                    grid[x - 1][y] == 4)
                    isPossible |= func(grid, x - 1, y);

            // right
            if (isValid(x, y + 1) && !vis[x][y + 1])
                if (grid[x][y + 1] == 1 || grid[x][y + 1] == 3 ||
                    grid[x][y + 1] == 5)
                    isPossible |= func(grid, x, y + 1);
        }

        return isPossible;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vis.assign(n, vector<bool>(m, false));

        return func(grid, 0, 0);
    }
};