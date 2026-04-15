class Solution {
public:
    int n;
    int solve(int i, int buy, vector<int>& prices, vector<vector<int>>&dp){
        if(i == n){
            return 0;
        }
        if(dp[i][buy] != -1) return dp[i][buy];
        
        int profit = 0;
        if(buy == 1){
            int bought = -prices[i] + solve(i+1, 0, prices, dp);
            int notbt = solve(i+1, 1, prices, dp);
            profit = max(bought, notbt);
        }else{
            int sell = prices[i] + solve(i+1, 1, prices, dp);
            int notsld = solve(i+1, 0, prices, dp);
            profit = max(sell, notsld);
        }

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        int buy = 1;
        return solve(0, buy, prices, dp);
    }
};