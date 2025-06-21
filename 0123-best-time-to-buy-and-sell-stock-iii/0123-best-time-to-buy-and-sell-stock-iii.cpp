class Solution {
public:
    int n;

    int f(int i, int buy, int count, vector<int>& prices, vector<vector<vector<int>>> &dp){
        if(i == n){
            return 0;
        }
        if(count == 0){
            return 0;
        }

        if(dp[i][buy][count] != -1){
            dp[i][buy][count];
        }

        int profit = 0;

        if(buy == 1){
            int bought = -prices[i] + f(i+1, 0, count, prices, dp);
            int notBought = f(i+1, 1, count, prices, dp);
            profit = max(bought, notBought);
        }
        else{
            int sold = prices[i] + f(i+1, 1, count - 1, prices, dp);
            int notSold = f(i+1, 0, count, prices, dp);
            profit = max(sold, notSold);
        }

        return dp[i][buy][count] = profit;
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();

        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

        // return f(0, 1, 2, prices, dp);

        //tabulation
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int i = n-1 ; i >= 0 ; i--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                for(int count = 1 ; count <= 2 ; count++){

                    int profit = 0;

                    if(buy == 1){
                        int bought = -prices[i] + dp[i+1][0][count];
                        int notBought = dp[i+1][1][count];
                        profit = max(bought, notBought);
                    }
                    else{
                        int sold = prices[i] + dp[i+1][1][count - 1];
                        int notSold = dp[i+1][0][count];
                        profit = max(sold, notSold);
                    }

                    dp[i][buy][count] = profit;
                }
            }
        }

        return dp[0][1][2];

    }
};