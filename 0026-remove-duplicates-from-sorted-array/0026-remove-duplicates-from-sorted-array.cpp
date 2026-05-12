class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int i = 0, k = 1;

        while(k < n){

            while(k < n and nums[k] == nums[i]){
                k++;
            }

            if(k < n){
                nums[i+1] = nums[k];
                i++;
            }
        }

        return i+1;
    }
};