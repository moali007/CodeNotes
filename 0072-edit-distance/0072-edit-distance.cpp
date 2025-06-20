class Solution {
public:
    int n, m;

    int f(int i, int j, string &word1, string &word2, vector<vector<int>> &dp){
        if(j == m){
            return n - i;
        }
        if(i == n){
            return m - j;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(word1[i] == word2[j]){
            return dp[i][j] = f(i+1, j+1, word1, word2, dp);
        }

        int insert = 1 + f(i, j+1, word1, word2, dp);
        int delet  = 1 + f(i+1, j, word1, word2, dp);
        int replace = 1 + f(i+1, j+1, word1, word2, dp);

        return dp[i][j] = min(insert, min(delet, replace));
    }

    int minDistance(string word1, string word2) {
        n = word1.length();
        m = word2.length();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return f(0, 0, word1, word2, dp);
    }
};