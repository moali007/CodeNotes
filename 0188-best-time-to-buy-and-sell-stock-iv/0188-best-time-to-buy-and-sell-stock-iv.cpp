class Solution {
public:
    int n;
    int solve(int i, int buy, int k, vector<int>& prices, vector<vector<vector<int>>>&dp){
        if(i == n){
            return 0;
        }
        if(k == 0){
            return 0;
        }
        if(dp[i][buy][k] != -1) return dp[i][buy][k];

        int profit = 0;
        if(buy == 1){
            int bought = -prices[i] + solve(i+1, 0, k, prices, dp);
            int notbt = solve(i+1, 1, k, prices, dp);
            profit = max(bought, notbt);
        }else{
            int sold = prices[i] + solve(i+1, 1, k-1, prices, dp);
            int notsld = solve(i+1, 0, k, prices, dp);
            profit = max(sold, notsld);
        }

        return dp[i][buy][k] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(k+1, -1)));
        int buy = 1;
        return solve(0, buy, k, prices, dp);
    }
};