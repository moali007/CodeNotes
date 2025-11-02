class Solution {
public:
    void mark(int r, int c, vector<vector<char>> &grid, int m, int n) {
        // up
        for (int i = r - 1; i >= 0 && grid[i][c] != 'W' && grid[i][c] != 'G'; i--) {
            grid[i][c] = '0';
        }
        // down
        for (int i = r + 1; i < m && grid[i][c] != 'W' && grid[i][c] != 'G'; i++) {
            grid[i][c] = '0';
        }
        // left
        for (int j = c - 1; j >= 0 && grid[r][j] != 'W' && grid[r][j] != 'G'; j--) {
            grid[r][j] = '0';
        }
        // right
        for (int j = c + 1; j < n && grid[r][j] != 'W' && grid[r][j] != 'G'; j++) {
            grid[r][j] = '0';
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> grid(m, vector<char>(n, '1'));

        // mark guards and walls
        for (auto &g : guards) grid[g[0]][g[1]] = 'G';
        for (auto &w : walls) grid[w[0]][w[1]] = 'W';

        // mark guarded cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'G') {
                    mark(i, j, grid, m, n);
                }
            }
        }

        // count unguarded
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') cnt++;
            }
        }

        return cnt;
    }
};
