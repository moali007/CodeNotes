class Solution {
public:
    int n;
    int f(int i, vector<int>& nums, int prevIdx, vector<vector<int>> &dp){
        if(i == n){
            return 0;
        }

        if(dp[i][prevIdx + 1] != -1){
            return dp[i][prevIdx + 1];
        }

        int skip = f(i+1, nums, prevIdx, dp);

        int take = 0;
        if(prevIdx == -1 || nums[i] > nums[prevIdx]){
            take = 1 + f(i+1, nums, i, dp);
        }

        return dp[i][prevIdx + 1] = max(skip, take);
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return f(0, nums, -1, dp);

        vector<int> temp;
        temp.push_back(nums[0]);

        for(int i = 1 ; i < n ; i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[idx] = nums[i];
            }
        }

        return temp.size();
    }
};