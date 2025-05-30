class Solution {
public:
    
    int M = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        //pre-compute power
        vector<int> power(n);
        power[0] = 1; // 2^0

        for(int i=1;i<n;i++){
            power[i] = (power[i-1] * 2) % M;
        }

        int s = 0, e = n-1;
        
        int ans = 0;
        while(s <= e){
            if(nums[s] + nums[e] <= target){
                int d = e - s;

                ans = (ans % M + power[d] % M) % M;
                s++;
            }
            else e--;
        }

        return ans % M;
    }
};