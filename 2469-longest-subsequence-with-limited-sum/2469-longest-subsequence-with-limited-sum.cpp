class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();

        vector<int> ans(m);
        
        sort(nums.begin(), nums.end());
        //store prefixSum of nums in nums
        for(int i=1;i<n;i++){
            nums[i] += nums[i-1];
        }

        for(int i=0;i<m;i++){
            int q = queries[i];

            int idx = upper_bound(nums.begin(), nums.end(), q) - nums.begin() - 1;
            
            ans[i] = (idx == -1) ? 0 : idx+1;
        }

        return ans;
    }
};