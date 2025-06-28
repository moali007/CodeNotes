class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<pair<int,int>> arr; //{nums[i], i}
        for(int i=0;i<n;i++){
            arr.push_back({nums[i], i});
        }

        sort(rbegin(arr), rend(arr));

        map<int, int> mp; //{index - element}
        for(int i=0;i<k;i++){
            auto curr = arr[i];
            mp[curr.second] = curr.first;
        }

        vector<int> ans;
        for(auto it : mp){
            ans.push_back(it.second);
        }

        return ans;
    }
};