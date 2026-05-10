class Solution {
public:
    int n;

    int f(int i, vector<int>& nums, int target, vector<int> &dp) {
        if(i == n - 1) {
            return 0;
        }

        if(dp[i] != -1) return dp[i];

        int ans = -1e9;

        for(int j = i + 1; j < n; j++) {

            if(abs(nums[j] - nums[i]) <= target) {
                int temp = 1 + f(j, nums, target, dp);

                ans = max(ans, temp);
            }
        }

        return dp[i] = ans;
    }

    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();
        
        vector<int> dp(n, -1);
        int ans = f(0, nums, target, dp);

        return ans < 0 ? -1 : ans;
    }
};