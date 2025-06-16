class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();

        int maxdiff = -1;
        
        int i=0,j=1;

        while(j < n){
            if(nums[i] >= nums[j]){
                i=j;
                j++;
            }else{
                int diff = nums[j] - nums[i];
                maxdiff = max(maxdiff, diff);
                j++;
            }
        }


        return maxdiff;
    }
};