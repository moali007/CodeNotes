class Solution {
public:
    int n;
    int f(int i, int prev, vector<int>&nums){
        if(i == n){
            return 0;
        }

        int nt = f(i+1, prev, nums);
        int take = 0;
        if(prev == -1 || nums[i] > nums[prev]){
            take = 1 + f(i+1, i, nums);
        }

        return max(nt, take);
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();

        return f(0, -1, nums);
    }
};