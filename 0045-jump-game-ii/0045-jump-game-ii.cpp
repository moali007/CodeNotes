class Solution {
public:  
    int n;

    int f(int i, vector<int> &nums, vector<int> &dp){
        if(i >= n-1){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }
         
        int minSteps = 1e9;

        for(int j = 1; j <= nums[i]; j++){

            minSteps = min(minSteps, 1 + f(i+j, nums, dp));
        }

        return dp[i] = minSteps;
    }
    

    int jump(vector<int>& nums) {
        n = nums.size();
        
        vector<int> dp(n+1, -1);
        return f(0, nums, dp);
    }
};