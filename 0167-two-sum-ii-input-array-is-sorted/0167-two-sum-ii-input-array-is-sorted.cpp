class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        int l = -1, r = -1;
        int i = 0, j = n-1;

        while(j < n){
            int sum = nums[i] + nums[j];
            if(sum == target){
                l = i, r = j;
                break;
            }
            else if(sum > target){
                j--;
            }
            else
                i++;
        }

        return {l+1, r+1};
    }
};