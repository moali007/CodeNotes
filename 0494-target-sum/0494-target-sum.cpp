class Solution {
public:
    
    int mem(int i,int sum,vector<int>& arr,vector<vector<int>> &dp){
	   // if(sum == 0) return 1;
	    if(i == 0){
	        if(sum == 0 && arr[0] == 0) return 2;
	        if(sum == 0 || sum == arr[0]) return 1;
	        return 0;
	    }
	    
	    if(dp[i][sum] != -1) return dp[i][sum];
	    
	    int notPick = mem(i-1,sum,arr,dp);
	    int pick = 0;
	    if(arr[i] <= sum)
	    pick = mem(i-1,sum-arr[i],arr,dp);
	    
	    dp[i][sum] = notPick+ pick;
	    return dp[i][sum];
	}
  
    int countPartitions(int n, int d, vector<int>& arr) {
        
        int total = accumulate(arr.begin(),arr.end(),0);
        
        if(total - d < 0 || (total - d) % 2 != 0) return 0;
        // sort(arr.rbegin(),arr.rend());
        int target = (total - d)/2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return mem(n-1, target, arr, dp);
        
    }
    int n;
    int f(int i, vector<int>& nums, int target){
        if(i == n){
            if(target == 0) return 1;
            return 0;
        }

        int sum = f(i+1, nums, target + nums[i]);
        int diff = f(i+1, nums, target - nums[i]);

        return sum + diff;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        n=nums.size();
        // return countPartitions(n,target,nums);
        return f(0, nums, target);
    }
};