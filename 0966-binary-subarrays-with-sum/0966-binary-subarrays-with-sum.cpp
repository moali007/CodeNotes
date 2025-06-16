class Solution {
public:
    int f(vector<int>& nums, int goal){
        int n = nums.size();
        if(goal<0) return 0;

        int i=0,j=0;
        int cnt = 0;
        int sum = 0;

        while(j < n){
            sum += nums[j];

            while(sum > goal){
                sum -= nums[i];
                i++;
            }

            if(sum <= goal){
                cnt += (j-i+1);
            }

            j++;
        }

        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {

        int a = f(nums,goal); //no. of subarrays with sum<= goal
        int b = f(nums,goal-1);//no. of subarrays with sum<= goal-1


        return a-b;
    }
};