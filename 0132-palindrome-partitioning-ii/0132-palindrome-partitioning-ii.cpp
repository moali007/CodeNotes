class Solution {
public:
    int n;

    bool isPallindrome(string &s, int i, int j){
        while(i <= j){
            if(s[i] != s[j]) return false;
            else{
                i++, j--;
            }
        }

        return true;
    }

    int f(int i, string &s, vector<int> &dp){
        if(i == n){
            return 0;
        }

        if(dp[i] != -1) return dp[i];

        int mini = INT_MAX;
        for(int j = i; j < n; j++){
            if(isPallindrome(s, i, j)){
                mini = min(mini, 1 + f(j+1, s, dp));
            }
        }

        return dp[i] = mini;
    }

    int minCut(string s) {
        n = s.length();
        
        vector<int> dp(n+1, -1);
        return f(0, s, dp) - 1;
    }
};