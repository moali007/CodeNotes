class Solution {
public:
    int n;
    bool f(int i, vector<int>& nums, vector<int> &dp){
        if(i >= n-1){
            return true;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        for(int j = 1; j <= nums[i]; j++){

            if(f(i + j, nums, dp) == true){
                return true;
            }
        }

        return dp[i] = false;
    }

    bool canJump(vector<int>& nums) {
        n = nums.size();
        if(n == 1) return true;
        vector<int> dp(n+1, -1);
        return f(0, nums, dp);
    }
};