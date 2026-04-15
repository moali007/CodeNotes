class Solution {
public:
    int n;
    int f(int i, int buy, vector<int>&prices, vector<vector<int>>&dp){
        if(i >= n){
            return 0;
        }
        if(dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;
        if(buy == 1){
            int bought = -prices[i] + f(i+1, 0, prices, dp);
            int notbuy = f(i+1, 1, prices, dp);
            profit = max(bought, notbuy);
        }else{
            int sold = prices[i] + f(i+2, 1, prices, dp);
            int notsld = f(i+1, 0, prices, dp);
            profit = max(sold, notsld);
        }

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        
        vector<vector<int>> dp(n+1, vector<int>(3, -1));
        int buy = 1;
        return f(0, buy, prices, dp);
    }
};