class Solution {
public:
    int n;
    
    int f(int i, vector<int>& prices, int buy){
        if(i == n){
            return 0;
        }

        int profit = 0;
        if(buy == 1){
            int bought = -prices[i] + f(i+1, prices, 0);
            int notBought = f(i+1, prices, 1);
            profit = max(bought, notBought);
        }
        else{
            int sold = prices[i] + f(i+1, prices, 1);
            int notSold = f(i+1, prices, 0);
            profit = max(sold, notSold);
        }

        return profit;
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();

        // int buy = 1;
        // return f(0, prices, buy);

        int profit = 0;

        for(int i=1 ; i<n ; i++){
            if(prices[i] > prices[i-1]){
                profit += prices[i] - prices[i-1];
            }
        }

        return profit;
    }
};