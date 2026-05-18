class Solution {
public:
    int n1, n2;

    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(i == n1 || j == n2){
            return 0;
        }

        if(dp[i][j] != -1){
           return dp[i][j]; 
        }

        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + f(i+1, j+1, s1, s2, dp);
        }

        return dp[i][j] = max(f(i, j+1, s1, s2, dp), f(i+1, j, s1, s2, dp));
    }

    int longestCommonSubsequence(string s1, string s2) {
        n1 = s1.length();
        n2 = s2.length();
        
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        return f(0, 0, s1, s2, dp);
    }
};