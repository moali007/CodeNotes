class Solution {
public:
    
    int bSearch(vector<int>& nums,int target){
        int n = nums.size();
        int l = 0;
        int h = n-1;

        while(l <= h){
            int mid = l + (h-l)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                l = mid + 1;
            }
            else{
                h = mid - 1;
            }
        }
        return -1;
    }

    int searchInsert(vector<int>& nums, int target) {

        // int idx = bSearch(nums,target);

        // if(idx != -1) return idx;

        int idx = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        return idx;
    }
};