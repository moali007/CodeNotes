class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        int e=n-1;

        while(s<e){
            //remove duplicates from left and right
            while(s<e && nums[s] == nums[s+1]) s++;
            while(s<e && nums[e] == nums[e-1]) e--;

            int mid = s + (e-s)/2;
            if(nums[mid] > nums[e]){ //gadbad
                s = mid + 1;
            }else{
                e = mid;
            }
        }
        return nums[s];
    }
};