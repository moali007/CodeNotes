class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp; //{diff, index} diff = zero - one
        mp[0] = -1;
        int zero = 0;
        int one = 0;
        int maxlen = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == 0) zero++;
            else one++;

            int diff = zero - one;

            if(mp.count(diff)){
                maxlen = max(maxlen, i - mp[diff]);
            }else{
                mp[diff] = i;
            }
        }

        return maxlen;
    }
};
