class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp; 
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == key) mp[key].push_back(i);
        }

        vector<int> ans;

        for(int i = 0 ; i < n ; i++){
            vector<int> keyIdx = mp[key];

            for(int j : keyIdx){
                if(abs(i - j) <= k){
                    ans.push_back(i);
                }
            }

        }

        vector<int> res;
        res.push_back(ans[0]);

        for(int i=1;i<ans.size();i++){
            if(ans[i] == res.back()) continue;

            res.push_back(ans[i]);
        }

        return res;
    }
};