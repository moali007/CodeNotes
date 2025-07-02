class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        while(n > 1){
            for(int i = 0; i < n-1; i++){
                long long sum = nums[i] + nums[i+1];
                nums[i] = (sum) % 10;
            }
            n--;
        }

        return nums[0];
    }
};