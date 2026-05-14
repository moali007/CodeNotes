class Solution {
public:
    //Find max length subarray with target = sum(nums) - x
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int total = accumulate(nums.begin(), nums.end(), 0);

        int target = total - x;

        if(target < 0){
            return -1;
        }

        if(target == 0){
            return n;
        }

        unordered_map<int, int> mp; //{sum, idx}
        mp[0] = -1;

        int preSum = 0;
        int maxlen = -1;

        for(int i = 0; i < n; i++){
            preSum += nums[i];

            if(mp.count(preSum - target)){
                maxlen = max(maxlen, i - mp[preSum - target]);
            }

            if(mp.find(preSum) == mp.end()){
                mp[preSum] = i;
            }
        }

        return maxlen == -1 ? -1 : n - maxlen;
    }
};