class Solution {
public:
    void mark(int r, int c, vector<vector<char>> &grid, int m, int n) {
        int rr, cc;

        // Up
        rr = r - 1;
        while (rr >= 0 && grid[rr][c] != 'W' && grid[rr][c] != 'G') {
            grid[rr][c] = '0';
            rr--;
        }

        // Down
        rr = r + 1;
        while (rr < m && grid[rr][c] != 'W' && grid[rr][c] != 'G') {
            grid[rr][c] = '0';
            rr++;
        }

        // Left
        cc = c - 1;
        while (cc >= 0 && grid[r][cc] != 'W' && grid[r][cc] != 'G') {
            grid[r][cc] = '0';
            cc--;
        }

        // Right
        cc = c + 1;
        while (cc < n && grid[r][cc] != 'W' && grid[r][cc] != 'G') {
            grid[r][cc] = '0';
            cc++;
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
