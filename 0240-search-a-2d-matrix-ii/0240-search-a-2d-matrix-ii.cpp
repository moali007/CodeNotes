class Solution {
public:
   
    int binarySearch(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size() - 1;

        while(s<=e){
            int mid=s+(e-s)/2;

            if(nums[mid] == target){
                return true;
            }
            else if(nums[mid] < target){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row =matrix.size();
        //har row sorted hai to har row pe binary search lag jaega
        for(int i=0;i<row;i++){
           if(binarySearch(matrix[i],target) == true)
            return true;
        }
        return false;
    }
};