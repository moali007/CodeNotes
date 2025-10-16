class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int val) {
        unordered_map<int, int> mp;

        for(int num : nums){
            int r = ((num % val) + val) % val;

            mp[r]++;
        }

        int mex = 0;
        while(mp[mex % val] > 0){
            mp[mex % val]--;
            mex++;
        }

        return mex;
    }
};