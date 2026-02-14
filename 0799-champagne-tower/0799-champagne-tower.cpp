class Solution {
public:
    double solve(int poured, int i, int j, vector<vector<double>> &dp){
        if(i < 0 || j < 0 || j > i)
            return 0.0;

        if(i == 0 && j == 0)
            return poured;

        if(dp[i][j] != -1.0)
            return dp[i][j];

        double left = max(0.0, (solve(poured, i-1, j-1, dp) - 1.0) / 2.0);
        double right = max(0.0, (solve(poured, i-1, j, dp) - 1.0) / 2.0);

        return dp[i][j] = left + right;
    }

    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row+1, vector<double>(query_row+1, -1.0));
        return min(1.0, solve(poured, query_row, query_glass, dp));
    }
};