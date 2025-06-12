class Solution {
public:
    vector<vector<int>> result;
    
    void solve(vector<int> &nums, vector<int> &temp, unordered_set<int> &st){
        if(temp.size() == nums.size()){
            result.push_back(temp);
            return;
        }

        for(int i=0 ; i<nums.size() ; i++){
            if(!st.empty() && st.count(nums[i])) continue;


            temp.push_back(nums[i]);
            st.insert(nums[i]);

            solve(nums, temp, st);

            temp.pop_back();
            st.erase(nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;

        unordered_set<int> st;

        solve(nums, temp, st);

        return result;
    }
};