class Solution {
public:
    int n, m;
    int solve(int i, int j, string &s, string &t, vector<vector<int>>&dp){
        if(j == m){
            return 1;
        }
        if(i == n){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];

        int match = 0;
        if(s[i] == t[j]){
            match = solve(i+1, j+1, s, t, dp);
        }

        int nm = solve(i+1, j, s, t, dp);

        return dp[i][j] = match + nm;
    }

    int numDistinct(string s, string t) {
        n = s.length();
        m = t.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(0, 0, s, t, dp);
    }
};