class Solution {
public:
    vector<pair<int, int>> arr = {{100, 0}, {75,25}, {50,50}, {25, 75}};
    double solve(int A, int B, vector<vector<double>> &dp) {
        if(A <= 0 and B <= 0) return 0.5;
        if(A<=0) return 1.0;
        if(B<=0) return 0.0;

        if(dp[A][B] != -1) return dp[A][B];

        double p = 0.0;
        for(auto it: arr) {
            int a = it.first;
            int b = it.second;
            p += solve(A-a, B-b, dp);
        }
        return dp[A][B] = 0.25*p;
    }
    double soupServings(int n) {
        if(n > 4800) return 1.0;
        vector<vector<double>> dp(n+1, vector<double>(n+1, -1));
        return solve(n, n, dp);
    }
};