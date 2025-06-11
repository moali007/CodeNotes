class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        int i=0;
        int j=n-1;
        int left = -1;
        int right = -1;
        while(i < j){
            if(nums[i] + nums[j] == target){
                left = i+1;
                right = j+1;
                break;
            }
            else if(nums[i] + nums[j] > target){
                j--;
            }
            else i++;
        }

        return {left, right};
    }
};