class Solution {
public:  

    vector<vector<int>> ans;
    
    void f(int idx,vector<int>& nums){
        if(idx == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        unordered_set<int> st;
        for(int i=idx;i<nums.size();i++){
            if(st.find(nums[i]) != st.end()){
                continue;
            }

            st.insert(nums[i]);
            swap(nums[i],nums[idx]);

            f(idx+1,nums);
            
            swap(nums[i],nums[idx]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        f(0,nums);

        // set<vector<int>> st(ans.begin(),ans.end());

        // ans.clear();

        // for(auto it : st){
        //     ans.push_back(it);
        // }

        return ans;
        
    }
};