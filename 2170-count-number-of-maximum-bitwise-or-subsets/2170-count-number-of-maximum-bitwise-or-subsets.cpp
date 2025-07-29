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

    vector<int> arr;
    int cnt = 0;
    void f(int i, vector<int>& nums, int &maxOR){
        if(i == nums.size()){
            int OR = 0;
            for(int it : arr){
                OR = OR | it;
            }
            if(OR == maxOR) cnt++;
            return;
        }

        arr.push_back(nums[i]);
        f(i+1, nums, maxOR);

        arr.pop_back();
        f(i+1, nums, maxOR);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        n = nums.size();

        int maxOR = 0;
        for(int i = 0; i < n; i++){
            maxOR = maxOR | nums[i];
        }

        // int OR = 0;
        // return solve(0, nums, OR, maxOR);
        f(0, nums, maxOR);
        return cnt;
    }
};