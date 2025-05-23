class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //BRute force sol -  set
        //optimal - 2 pointer 
        int k=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i] != nums[k-1]){
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};