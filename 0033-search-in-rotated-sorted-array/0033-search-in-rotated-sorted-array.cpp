class Solution {
public:

  int binarySearch(vector<int> arr,int s,int e,int target){
      int mid=s+(e-s)/2;

      while(s<=e){
          if(arr[mid]==target){
              return mid;
          }
          else if(target<arr[mid]){
              e=mid-1;
          }
          else{
              s=mid+1;
          }
          mid=s+(e-s)/2;
      }
      return -1;
  }

    int findPivot(vector <int> arr){
        int n=arr.size();
        int s=0;
        int e=n-1;

        while(s<e){
            int mid=s+(e-s)/2;
            if(arr[mid] > arr[e]){
                s=mid+1;
            }else{
                e=mid;
            }
        }
        return e;
    }


    int search(vector<int>& nums, int target) {
        int pivotIndex=findPivot(nums);
        
        int index = binarySearch(nums,0,pivotIndex-1,target); //left side of pivot index

        if(index != -1){
            return index;
        }
        
        index = binarySearch(nums,pivotIndex,nums.size()-1,target); //right side of pivot index
        return index;

    }
};