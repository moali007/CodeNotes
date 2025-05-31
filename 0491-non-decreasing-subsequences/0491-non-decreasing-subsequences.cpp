class Solution {
public:

    vector<vector<int>> ans;
    
    void f(int i, vector<int>& nums, vector<int>& arr){
        if(i == nums.size()){
            return;
        }

        //not take
        f(i+1, nums, arr);

        //take
        if(arr.empty() || nums[i] >= arr.back()){
            arr.push_back(nums[i]); //take //do

            if(arr.size() >= 2){
                ans.push_back(arr);
            }
            f(i+1, nums, arr);

            arr.pop_back(); //undo
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> arr;

        f(0, nums, arr);

        set<vector<int>> st(ans.begin(), ans.end());
        ans.clear();
        for(auto it : st){
            ans.push_back(it);
        }

        return ans;
    }
};