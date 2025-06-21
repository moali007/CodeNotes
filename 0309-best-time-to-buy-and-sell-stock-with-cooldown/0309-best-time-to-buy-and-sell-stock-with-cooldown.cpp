class Solution {
public:
    int n;
    
    int f(int i, int buy, vector<int>& prices, vector<vector<int>> &dp){
        if(i >= n){
            return 0;
        }

        if(dp[i][buy] != -1){
            return dp[i][buy];
        }

        int profit = 0;
        if(buy == 1){
            //you can buy/not buy on current day
            int bought = -prices[i] + f(i+1, 0, prices, dp);
            int notBought = f(i+1, 1, prices, dp);
            profit = max(bought, notBought);
        }
        else{
            //you can sell/not sell on current day
            int sold = prices[i] + f(i+2, 1, prices, dp);
            int notSold = f(i+1, 0, prices, dp);
            profit = max(sold, notSold);
        }

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        
        // vector<vector<int>> dp(n+1, vector<int>(2, -1));
        // return f(0, 1, prices, dp);

        vector<vector<int>> dp(n+2, vector<int>(2, 0));

        for(int i = n-1 ; i >= 0 ; i--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                int profit = 0;
                if(buy == 1){
                    //you can buy/not buy on current day
                    int bought = -prices[i] + dp[i+1][0];
                    int notBought = dp[i+1][1];
                    profit = max(bought, notBought);
                }
                else{
                    //you can sell/not sell on current day
                    int sold = prices[i] + dp[i+2][1];
                    int notSold = dp[i+1][0];
                    profit = max(sold, notSold);
                }

                dp[i][buy] = profit;
            }
        }

        return dp[0][1];
    }
};