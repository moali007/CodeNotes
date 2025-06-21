class Solution {
public:
    int n;
    
    int f(int i, vector<int>& prices, int buy, vector<vector<int>> &dp){
        if(i == n){
            return 0;
        }

        if(dp[i][buy] != -1){
            return dp[i][buy];
        }

        int profit = 0;
        if(buy == 1){
            int bought = -prices[i] + f(i+1, prices, 0, dp);
            int notBought = f(i+1, prices, 1, dp);
            profit = max(bought, notBought);
        }
        else{
            int sold = prices[i] + f(i+1, prices, 1, dp);
            int notSold = f(i+1, prices, 0, dp);
            profit = max(sold, notSold);
        }

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();
 
        int buy = 1;
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, prices, buy, dp);
        


        //simple O(n) solution - No dp needed here
        // int profit = 0;

        // for(int i=1 ; i<n ; i++){
        //     if(prices[i] > prices[i-1]){
        //         profit += prices[i] - prices[i-1];
        //     }
        // }

        // return profit;
    }
};