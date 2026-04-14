class Solution {
public:
    int n, m;
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>>&dp){
        if(i == n){
            return m - j;
        }
        if(j == m){
            return n - i;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]){
            return solve(i+1, j+1, s1, s2, dp);
        }

        int ins = 1 + solve(i, j+1, s1, s2, dp);
        int del = 1 + solve(i+1, j, s1, s2, dp);
        int rep = 1 + solve(i+1, j+1, s1, s2, dp);

        return dp[i][j] = min({ins, del, rep});
    }

    int minDistance(string word1, string word2) {
        n = word1.size();
        m = word2.size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(0, 0, word1, word2, dp);
    }
};