class Solution {
public:

    int findLeftMostIndex(vector<int>& nums, int target,int n){
        int s=0;
        int e=n-1;
        int leftIndex = -1;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(nums[mid] == target){
                leftIndex = mid; //possible ans,search more left
                e = mid-1;
            }
            else if(nums[mid] < target){
                s = mid+1;
            }
            else{
                e = mid - 1;
            }
        }
        return leftIndex;
    }

    int findRightMostIndex(vector<int>& nums, int target,int n){
        int s=0;
        int e=n-1;
        int rightIndex = -1;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(nums[mid] == target){
                rightIndex = mid; //possible ans,search more right
                s = mid+1;
            }
            else if(nums[mid] < target){
                s = mid+1;
            }
            else{
                e = mid - 1;
            }
        }
        return rightIndex;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int left_index = findLeftMostIndex(nums,target,n);
        int right_index = findRightMostIndex(nums,target,n);

        return {left_index,right_index};
    }
};