class Solution {
public:
    int n;
    
    int f(int i, vector<int>& nums, int target){
        if(i == n-1){
            return 0;
        }

        int ans = INT_MIN;
        for(int j = i+1; j < n; j++){
            if(abs(nums[j] - nums[i]) <= target){
                int temp =  1 + f(j, nums, target);

                ans = max(ans, temp);
            }
        }

        return ans;
    }

    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();

        int ans = f(0, nums, target);

        return ans < 0 ? -1 : ans;
    }
};