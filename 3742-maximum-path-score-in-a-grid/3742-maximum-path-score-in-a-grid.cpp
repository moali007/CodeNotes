class Solution {
public:
    int n, m;
    
    int f(int i, int j, vector<vector<int>>& grid, int &k, int cost, vector<vector<vector<int>>>&dp){
        if(i < 0 || j < 0){
            return INT_MIN;
        }

        int newCost = cost + (grid[i][j] > 0 ? 1 : 0);
        if(newCost > k){
            return INT_MIN;
        }

        if(i == 0 and j == 0){
            return grid[i][j];
        }

        if(dp[i][j][cost] != -1) return dp[i][j][cost];

        int left = f(i, j-1, grid, k, newCost, dp);
        int up = f(i-1, j, grid, k, newCost, dp);
        
        if(left == INT_MIN and up == INT_MIN) return INT_MIN;
        return dp[i][j][cost] = max(up, left) + grid[i][j];
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();

        int cost = 0;
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(k+1, -1)));
        // int ans = f(n-1, m-1, grid, k, cost, dp);
        // if(ans == INT_MIN) return -1;
        // return ans;

        //tab
        // dp[i][j][c] = max score reaching (i,j) using c cost
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k+1, INT_MIN)));

        int startCost = (grid[0][0] > 0 ? 1 : 0);
        if(startCost <= k) {
            dp[0][0][startCost] = grid[0][0];
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int c = 0; c <= k; c++){
                    if(dp[i][j][c] == INT_MIN) continue;

                    // move DOWN
                    if(i + 1 < n){
                        int newCost = c + (grid[i+1][j] > 0 ? 1 : 0);
                        if(newCost <= k){
                            dp[i+1][j][newCost] = max(
                                dp[i+1][j][newCost],
                                dp[i][j][c] + grid[i+1][j]
                            );
                        }
                    }

                    // move RIGHT
                    if(j + 1 < m){
                        int newCost = c + (grid[i][j+1] > 0 ? 1 : 0);
                        if(newCost <= k){
                            dp[i][j+1][newCost] = max(
                                dp[i][j+1][newCost],
                                dp[i][j][c] + grid[i][j+1]
                            );
                        }
                    }
                }
            }
        }

        // answer = max over all cost ≤ k at destination
        int ans = INT_MIN;
        for(int c = 0; c <= k; c++){
            ans = max(ans, dp[n-1][m-1][c]);
        }

        return (ans == INT_MIN) ? -1 : ans;
    }
};