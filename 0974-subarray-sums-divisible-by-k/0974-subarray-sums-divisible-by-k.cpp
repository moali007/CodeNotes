class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp; //{remainder, count}
        mp[0] = 1;

        int preSum = 0;
        int cnt = 0;

        for(int i = 0; i < n; i++){
            preSum += nums[i];

            int rem = preSum % k;
            if(rem < 0) rem += k; //negative rem not possible

            cnt += mp[rem];

            mp[rem]++;
        }

        return cnt;
    }
};