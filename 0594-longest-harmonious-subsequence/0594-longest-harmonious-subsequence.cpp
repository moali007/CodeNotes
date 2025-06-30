class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;
        for(int num : nums){
            mp[num]++;
        }

        int len = 0;
        for(auto it : mp){
            int num = it.first;
            int freq = it.second;

            if(mp.count(num+1)){
                len = max(len, freq + mp[num+1]);
            }
        }

        return len;
    }
};