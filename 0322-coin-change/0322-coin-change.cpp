class Solution {
public:
    int n;

    int solve(int i, vector<int>& coins, int amount, vector<vector<int>>&dp){
        if(i == 0){
            if(amount % coins[i] == 0) return amount/coins[i];
            else return 1e9;
        }

        if(dp[i][amount] != -1) return dp[i][amount];

        int nt = 0 + solve(i-1, coins, amount, dp);
        int take = 1e9;
        if(coins[i] <= amount){
            take = 1 + solve(i, coins, amount - coins[i], dp);
        }

        return dp[i][amount] = min(take, nt);
    }

    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        int ans =  solve(n-1, coins, amount, dp);
        if(ans == 1e9) return -1;
        return ans;
    }
};