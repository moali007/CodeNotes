class Solution {
public:
    
    int n;

    int f(int i, vector<int>& nums, int prevIdx){
        if(i == n){
            return 0;
        }

        int notPick = f(i+1, nums, prevIdx);
        
        int pick = 0;
        if(prevIdx == -1 || nums[i] > nums[prevIdx]){
            prevIdx = i;
            pick = 1 + f(i+1, nums, prevIdx);
        }

        return max(pick, notPick);

    }

    int memF(int i, vector<int>& nums, int prevIdx, vector<vector<int>> &dp){
        if(i == n){
            return 0;
        }

        if(dp[i][prevIdx+1] != -1){
            return dp[i][prevIdx+1];
        }

        int notPick = memF(i+1, nums, prevIdx, dp);
        
        int pick = 0;
        if(prevIdx == -1 || nums[i] > nums[prevIdx]){
            // prevIdx = i;
            pick = 1 + memF(i+1, nums, i, dp);
        }

        return dp[i][prevIdx+1] = max(pick, notPick);

    }

    int lengthOfLIS(vector<int>& nums) {
       n = nums.size(); 
    //    int prevIdx = -1;
    // return f(0, nums, prevIdx);
       vector<vector<int>> dp(n, vector<int>(n+1, -1));
       return memF(0, nums, -1, dp);

        //Tabulation
        // vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        // for(int i=n-1;i>=0;i--){
        //     for(int prevIdx = i-1;prevIdx >= -1; prevIdx--){

        //         int notPick = dp[i+1][prevIdx+1];
                
        //         int pick = 0;
        //         if(prevIdx == -1 || nums[i] > nums[prevIdx]){
        //             pick = 1 + dp[i+1][i+1];
        //         }

        //         dp[i][prevIdx+1] = max(pick, notPick);
        //     }
        // }
        // return dp[0][-1+1];


        //MOST OPTIMAL - Binary Search
        // vector<int> temp;
        // temp.push_back(nums[0]);

        // for(int i=1;i<n;i++){
        //     if(nums[i] > temp.back()){
        //         temp.push_back(nums[i]);
        //     }
        //     else{
        //         int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
        //         temp[idx] = nums[i];
        //     }
        // }

        // return temp.size();
    }
};