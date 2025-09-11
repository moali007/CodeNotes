class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();

        long xr = 0;
        for(int i = 0; i < n; i++){
            xr = xr ^ nums[i];
        }

        long rightmost = (xr & xr - 1) ^ xr;
        int b1 = 0, b2 = 0;

        for(int i = 0; i < n; i++){
            if((rightmost & nums[i]) == 0){
                b1 = b1 ^ nums[i];
            }
            else{
                b2 = b2 ^ nums[i];
            }
        }

        return {b1, b2};
    }
};