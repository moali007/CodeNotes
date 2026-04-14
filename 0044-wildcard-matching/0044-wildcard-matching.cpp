class Solution {
public:
    int n, m;

    bool solve(int i, int j, string &p, string &s, vector<vector<int>> &dp){
        if(i < 0 and j < 0){
            return true;
        }
        if(i < 0 and j >= 0){
            return false;
        }
        if(j < 0){
            while(i >= 0){
                if(p[i] != '*') return false;
                i--;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(p[i] == s[j] || p[i] == '?'){
            return dp[i][j] = solve(i-1, j-1, p, s, dp);
        }
        if(p[i] == '*'){
            return dp[i][j] = solve(i-1, j, p, s, dp) || solve(i, j-1, p, s, dp);
        }

        return false;
    }

    bool isMatch(string s, string p) {
        m = s.length();
        n = p.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(n-1, m-1, p, s, dp);
    }
};