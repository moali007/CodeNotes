class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        unordered_map<int, int> mp;
        for(int n1 : nums1){
            for(int n2 : nums2){
                int sum = n1 + n2;
                mp[sum]++;
            }
        }

        int count = 0;
        for(int n3 : nums3){
            for(int n4 : nums4){
                int sum = n3 + n4;
                int target = -sum;

                count += mp[target];
            }
        }

        return count;
    }
};