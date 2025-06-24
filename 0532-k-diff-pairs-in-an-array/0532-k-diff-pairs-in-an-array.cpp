class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]] = i;
        }

        int cnt = 0;
        for(int i=0;i<n;i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int target = nums[i] + k;

            if(mp.find(target) != mp.end() && mp[target] != i) cnt++;
        }

        return cnt;
    }
};