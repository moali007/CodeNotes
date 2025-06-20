class Solution {
public:

    int f(int ind1,int ind2,string str1,string str2){
        if(ind1 < 0 || ind2 < 0){
            return 0;
        }

        if(str1[ind1] == str2[ind2])
         return 1 + f(ind1-1,ind2-1,str1,str2);
        
        return max(f(ind1-1,ind2,str1,str2),f(ind1,ind2-1,str1,str2));

    }
    
    int mem(int ind1,int ind2,string &str1,string &str2,vector<vector<int>> &dp){
        if(ind1 < 0 || ind2 < 0){
            return 0;
        }

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        if(str1[ind1] == str2[ind2])
         return dp[ind1][ind2] = 1 + mem(ind1-1,ind2-1,str1,str2,dp);
        
        return dp[ind1][ind2] = max(mem(ind1-1,ind2,str1,str2,dp),mem(ind1,ind2-1,str1,str2,dp));

    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int LCS = mem(n-1,m-1,word1,word2,dp);
        
        return (n+m) - 2*LCS;

    }
};