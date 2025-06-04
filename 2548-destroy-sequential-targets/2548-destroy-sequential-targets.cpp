class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int ans = INT_MAX;
        int maxCnt = INT_MIN;

        for(auto num : nums){
            int rem = num % space;
            mp[rem]++;

            if(mp[rem] > maxCnt) maxCnt = mp[rem];  //keep track of the max count, with same reminder
        }

        for(auto num : nums){
            if(mp[num % space] == maxCnt){
                ans = min(ans, num);
            }
        }

        return ans;

    }
};