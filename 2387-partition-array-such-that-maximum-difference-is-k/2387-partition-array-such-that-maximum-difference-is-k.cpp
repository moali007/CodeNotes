class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i=0,j=0;
        int cnt = 1;
        while(j < n){
            if(nums[j] - nums[i] <= k){
                j++;
            }
            else{
                cnt++;
                i = j;
            }
        }

        return cnt;
    }
};