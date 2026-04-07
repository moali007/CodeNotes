class Solution {
public:
    // void nextPermutation(vector<int>& nums) {
    //     next_permutation(nums.begin(),nums.end());
    // }

    void nextPermutation(vector<int>& nums) {
        //step 1 : find dip index
        int ind = -1;
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
                if(i>0 && nums[i-1] < nums[i]){
                    ind = i-1;
                    break;
                }
            }
        if(ind==-1){
            reverse(nums.begin(),nums.end());
            // return nums;
        }
    
        else{
            for(int i=n-1;i>=ind;i--){
                if(nums[i]>nums[ind]){
                    swap(nums[i],nums[ind]);
                    break;
                }
            }

            reverse(nums.begin()+ind+1,nums.end());
            //  return nums;
        }
    }
};