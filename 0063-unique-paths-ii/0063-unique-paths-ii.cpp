class Solution {
public:
    int m,n;
    int f(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(r >= n || c >= m || grid[r][c] == 1){
            return 0;
        }

        if(r == n-1 && c == m-1){
            return 1;
        }

        if(dp[r][c] != -1){
            return dp[r][c];
        }

        //mtlb grid[r][c] == 0

        // grid[r][c] = 1; //mark

        int down = f(r+1, c, grid, dp);
        int right = f(r, c+1, grid, dp);

        // grid[r][c] = 0; //backtrack

        return dp[r][c] = down + right;

    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return f(0, 0, grid, dp);
        
    }
};