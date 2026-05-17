class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;
        mp[0] = -1;
        int presum = 0;

        for(int i = 0; i < n; i++){
            presum += nums[i];

            int rem = presum % k;

            if(mp.count(rem)){
                if(i - mp[rem] >= 2) 
                   return true;
            }else{
                mp[rem] = i;
            }
        }

        return false;
    }
};

