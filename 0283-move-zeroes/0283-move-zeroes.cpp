class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int k=0;

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
    }
};