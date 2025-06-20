class Solution {
public:
    int n,m;

    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(j == m){
            return 1;
        }
        if(i == n){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int match = 0;
        if(s[i] == t[j]){
            match = f(i+1, j+1, s, t, dp);
        }
        
        int notMatch = f(i+1, j, s, t, dp);

        return dp[i][j] = match + notMatch;
    }

    int numDistinct(string s, string t) {
        n = s.length();
        m = t.length();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return f(0, 0, s, t, dp);
    }
};