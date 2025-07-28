class Solution {
public:
    int n; 
    int solve(int i, vector<int>& nums, int OR, int &maxOR){
        if(i == n){
            return (OR == maxOR) ? 1 : 0;
        }

        int take = solve(i+1, nums, OR | nums[i], maxOR);

        int skip = solve(i+1, nums, OR, maxOR);

        return take + skip;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        n = nums.size();

        int maxOR = 0;
        for(int i = 0; i < n; i++){
            maxOR = maxOR | nums[i];
        }

        int OR = 0;
        return solve(0, nums, OR, maxOR);
    }
};