class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int i=0,j=0,sum=0,maxi=0;
        while(j<n) {
            mp[nums[j]]++;
            sum += nums[j];
            while(j-i+1 > mp.size()) {
                sum -= nums[i];
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            maxi = max(maxi, sum);
            j++;
        }
        return maxi;
    }
};