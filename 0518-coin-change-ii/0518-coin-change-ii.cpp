class Solution {
public:
    int n;

    int f(int i, int amount, vector<int>& coins, vector<vector<int>> &dp){
        if(amount == 0){
            return 1;
        }
        if(i == n){
            return 0;
        }

        if(dp[i][amount] != -1){
            return dp[i][amount];
        }

        int skip = f(i+1, amount, coins, dp);

        int take = 0;
        if(coins[i] <= amount)
          take = f(i, amount - coins[i], coins, dp);

        return dp[i][amount] = skip + take;
    }

    int change(int amount, vector<int>& coins) {
        n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return f(0, amount, coins, dp);
    }
};