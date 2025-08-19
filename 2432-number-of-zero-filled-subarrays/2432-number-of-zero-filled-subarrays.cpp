class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();

        long long cnt = 0;
        int i=0;
        
        while(i < n){
            long long l = 0;

            if(nums[i] == 0){
                while(i < n and nums[i] == 0){
                    i++;
                    l++;
                }
            }else{
                i++;
            }

            cnt += (l)*(l+1)/2;
        }

        return cnt;

        
    }
};