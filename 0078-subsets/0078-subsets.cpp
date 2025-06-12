class Solution {
public:
    vector<vector<int>> result;
    
    void solve(int i,vector<int> &v,vector<int>& nums){
        if(i == nums.size()){
            result.push_back(v);
            return;
        }

        //take
        v.push_back(nums[i]);
        solve(i+1,v,nums);

        v.pop_back();

        //not take
        solve(i+1,v,nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        solve(0,v,nums);
        return result;
    }
};