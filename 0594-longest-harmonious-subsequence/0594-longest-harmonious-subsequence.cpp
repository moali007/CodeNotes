class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int len = 0;
        int i=0,j=0;

        while(j < n){
            while(nums[j] - nums[i] > 1){
                i++;
            }

            if(nums[j] - nums[i] == 1){
                len = max(len, j-i+1);
            }

            j++;
        }

        return len;
    }
};