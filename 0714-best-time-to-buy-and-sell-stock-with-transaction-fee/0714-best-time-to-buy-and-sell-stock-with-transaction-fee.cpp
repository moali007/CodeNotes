class Solution {
public:
    int n;

    int f(int i, int buy, vector<int>& prices, int fee, vector<vector<int>> &dp){
        if(i == n){
            return 0;
        }

        if(dp[i][buy] != -1){
            return dp[i][buy];
        }

        int profit = 0;
        if(buy == 1){
            //you can buy/not buy on ith day
            int bought = -prices[i] + f(i+1, 0, prices, fee, dp);
            int notBought = f(i+1, 1, prices, fee, dp);
            profit = max(bought, notBought);
        }
        else{
            //you can sell/not sell on the ith day
            int sold = prices[i] - fee + f(i+1, 1, prices, fee, dp);
            int notSold = f(i+1, 0, prices, fee, dp);
            profit = max(sold, notSold);
        }

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        n = prices.size();
        
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, prices, fee, dp);
    }
};