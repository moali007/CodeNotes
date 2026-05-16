class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int s = 0, e = n-1;

        while(s < e){
            while(s < e and nums[s] == nums[s+1]) s++;
            while(e > s and nums[e] == nums[e-1]) e--;

            int mid = s + (e-s)/2;

            if(nums[mid] > nums[e]){
                s = mid + 1;
            }else{
                e = mid;
            }
        }

        return nums[e];

    }
};