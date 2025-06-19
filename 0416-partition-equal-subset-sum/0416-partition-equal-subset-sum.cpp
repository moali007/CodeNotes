class Solution {
public:
    
    bool f(int i, int target, vector<int> &nums, vector<vector<int>> &dp){
        if(target == 0){
            return true;
        }
        if(i < 0){
            return false;
        }

        if(dp[i][target] != -1){
            return dp[i][target];
        }

        bool notTake = f(i-1, target, nums, dp);
        bool take = false;
        if(nums[i] <= target)
           take = f(i-1, target - nums[i], nums, dp);
        
        return dp[i][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false;

        int target = sum/2;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return f(n-1, target, nums, dp);
    }
};