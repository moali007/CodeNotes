class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);
        unordered_map<int, vector<int>> mp; //{arr[i], {indexes}}

        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        for(auto it : mp){
            int num = it.first;
            vector<int> &indexes = it.second;

            long long totalSum = accumulate(indexes.begin(), indexes.end(), 0ll);
            int m = indexes.size();
            long long preSum = 0;

            for(int i=0;i<m;i++){
                int index = indexes[i];
                long long postSum = totalSum - preSum - index;

                ans[index] += (index * (long long)(i));
                ans[index] -= (preSum);
                ans[index] -= (index * (long long)(m-i-1));
                ans[index] += (postSum);

                preSum += index;
            }
        }

        return ans;
    }
};