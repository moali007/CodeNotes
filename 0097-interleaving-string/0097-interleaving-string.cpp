class Solution {
public:
    int n, m, N;
    int f(int i, int j, int k, string s1, string s2, string s3, vector<vector<vector<int>>>&dp){
        if(i == n and j == m and k == N){
            return true;
        }

        if(k == N){
            return false;
        }

        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }

        bool take_i = false;
        if(s1[i] == s3[k]){
            take_i = f(i+1, j, k+1, s1, s2, s3, dp);
        }

        bool take_j = false;
        if(s2[j] == s3[k]){
            take_j = f(i, j+1, k+1, s1, s2, s3, dp);
        }

        return dp[i][j][k] = take_i || take_j;
    }

    bool isInterleave(string s1, string s2, string s3) {
        n = s1.length();
        m = s2.length();
        N = s3.length();

        if(n + m != N) return false;
        
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(N+1, -1)));
        return f(0, 0, 0, s1, s2, s3, dp);
    }
};