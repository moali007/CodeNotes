class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();

        unordered_map<int, int> mp; //{preSum, cnt}
        mp[0] = 1;

        int preSum = 0;
        int cnt = 0;

        for(int i = 0; i < n; i++){
            preSum += nums[i];

            cnt += mp[preSum - goal];

            mp[preSum]++;
        }

        return cnt;
    }
};