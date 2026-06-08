class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        int countLessThanPivot = 0;
        int countEqualToPivot = 0;

        for(int i=0;i<n;i++){
            if(nums[i] < pivot) countLessThanPivot++;
            else if(nums[i] == pivot) countEqualToPivot++;
        }

        int i=0; //less than pivot iss idx se bhare jaenge
        int j = countLessThanPivot; //equal to pivot yaha se bhare jaenge
        int k = countLessThanPivot + countEqualToPivot; //greater than pivot yaha se bhare jange

        vector<int> ans(n);
        
        for(int num : nums){
            if(num < pivot){
                ans[i++] = num;
            }
            else if(num == pivot){
                ans[j++] = num;
            }
            else{
                ans[k++] = num;
            }
        }

        return ans;
    }
};