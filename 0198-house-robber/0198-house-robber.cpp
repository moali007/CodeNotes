class Solution {
public:
    int n;
    int f(int i, vector<int>& nums, vector<int> &dp){
        if(i >= n){
            return 0;
        }
        
        if(dp[i] != -1) return dp[i];

        int steal = nums[i] + f(i+2, nums, dp);

        int skip = f(i+1, nums, dp);

        return dp[i] = max(steal, skip);
    }

    int rob(vector<int>& nums) {
        n = nums.size();
        vector<int> dp(n, -1);
        return f(0, nums, dp);
    }
};