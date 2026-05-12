class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, vector<int>> mp; //{element, {indexes present}}
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }

        vector<long long> ans(n, 0);

        for(auto it : mp){
            int num = it.first;
            vector<int> indexes = it.second;
            int m = indexes.size();

            long long sum = 0;
            vector<long long> preSum(m, 0);
            for(int i = 0; i < m; i++){
                sum += indexes[i];
                preSum[i] = sum;
            }

            for(int i = 0; i < m; i++){
                long long leftSum = preSum[i] - indexes[i];
                int leftLength = i;
                long long leftDiff = 1LL * indexes[i] * leftLength - leftSum;

                long long rightSum = preSum[m-1] - indexes[i] - leftSum;
                int rightLength = m - i - 1;
                long long rightDiff = rightSum - 1LL * indexes[i] * rightLength;

                ans[indexes[i]] = leftDiff + rightDiff;
            }
        }

        return ans;
    }
};