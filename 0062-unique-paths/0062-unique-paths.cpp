class Solution {
public:
    
    int f(int r, int c, int m, int n){
        if(r >= m || c >= n){
            return 0;
        }

        if(r == m-1 && c == n-1){
            return 1; //ek valid path mil gya
        }

        int down = f(r+1, c, m, n);
        int right = f(r, c+1, m, n);

        return down + right;

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
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return mem(0, 0, m, n, dp);
    }
};