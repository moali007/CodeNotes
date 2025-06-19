class Solution {
public:
    
    int f(int r, int c, int m, int n){
        if(r >= m || c >= n){
            return 0;
        }

        if(r == m-1 && c == n-1){
            return 1; //ek valid path mil gya
        }

        //koi grid hoti to mark kar deta curr path, but koi grid nahi to age badho

        int down = f(r+1, c, m, n);
        int right = f(r, c+1, m, n);

        return down + right;

    }

    int solve(int i, int j, int m,int n, vector<vector<int>> &dp){
        if(i == 0 && j == 0){
            return 1;
        }
        if(i < 0 || j < 0){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int left = solve(i, j-1, m, n, dp);
        int up = solve(i-1, j, m, n, dp);

        return dp[i][j] = left+up;
    }

    int mem(int r, int c, int m, int n, vector<vector<int>> &dp){
        if(r >= m || c >= n){
            return 0;
        }

        if(r == m-1 && c == n-1){
            return 1; //ek valid path mil gya
        }

        if(dp[r][c] != -1) return dp[r][c];

        int down = mem(r+1, c, m, n, dp);
        int right = mem(r, c+1, m, n, dp);

        return dp[r][c] = down + right;

    }

    int uniquePaths(int m, int n) {
        //m -> row
        //n -> col
        // return f(0, 0 , m, n);
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return mem(0, 0, m, n, dp);
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m-1, n-1, m, n, dp);
    }
};