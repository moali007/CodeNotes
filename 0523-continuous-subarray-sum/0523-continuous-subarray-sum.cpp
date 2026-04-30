class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp; //{rem, index they have been seen}
        mp[0] = -1;
        int preSum = 0;

        for(int i = 0; i < n; i++){
            preSum += nums[i];

            int rem = preSum % k;

            if(mp.count(rem)){
                if( i - mp[rem] >= 2) return true;
            }else mp[rem] = i;
        }

        return false;
    }
};