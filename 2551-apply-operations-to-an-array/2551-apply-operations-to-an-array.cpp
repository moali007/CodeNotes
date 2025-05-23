class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        for(int i=0;i<n-1;i++){
            if(nums[i] == nums[i+1]){
                nums[i] = 2*nums[i];
                nums[i+1] = 0;
            }
        }

        //now using in-place code of move zeros to end problem
        int k = 0;
        for(int i=0;i<n;i++){
            if(nums[i] != 0){
                nums[k] = nums[i];
                k++;
            }
        }

        while(k < n){
            nums[k] = 0;
            k++;
        }

        return nums;
    }
};