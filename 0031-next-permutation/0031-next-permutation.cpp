class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int dipIdx = -1;

        for(int i = n-1; i >= 0; i--){
            if(i-1 >= 0 and nums[i-1] < nums[i]){
                dipIdx = i-1;
                break;
            }
        }

        if(dipIdx == -1){
            reverse(nums.begin(), nums.end());
        }
        else{
            for(int i = n-1; i >= 0; i--){
                if(nums[i] > nums[dipIdx]){
                    swap(nums[i], nums[dipIdx]);
                    break;
                }
            }

            reverse(nums.begin() + dipIdx + 1, nums.end());
        }
    }
};