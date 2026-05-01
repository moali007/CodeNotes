class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        int k = sum - x;
        // Edge cases
        if(k < 0) return -1;
        if(k == 0) return n;
        //Find max len subarray with sum = k
        unordered_map<int, int> mp; //{preSum, index}
        mp[0] = -1;
        int preSum = 0;
        int maxlen = INT_MIN;

        for(int i = 0; i < n; i++){
            preSum += nums[i];

            if(mp.count(preSum - k)){
                maxlen = max(maxlen, i - mp[preSum - k]);
            }
            
            if(mp.find(preSum) == mp.end()){
                mp[preSum] = i;
            }
        }

        if(maxlen == INT_MIN) return -1;
        return n - maxlen;
    }
};