class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int closest_sum = 1e5; 

        for(int i=0;i<n;i++){
            int j=i+1;
            int k=n-1;

            while(j < k){
                int current_sum = nums[i] + nums[j] + nums[k];
               
                if(abs(current_sum - target) < abs(closest_sum - target)){
                    closest_sum = current_sum;
                }
                if(current_sum < target){
                    j++;
                }
                else if(current_sum > target){
                    k--;
                }
                else{
                    return current_sum;
                }
            }
        }

        return closest_sum;
    }
};