class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        int maxi = 0;
        int prefixProd = 1;

        for(int i = 0 ; i < n ; i++){
            prefixProd *= nums[i];

            if(prefixProd > maxi){
                maxi = prefixProd;
            }

            if(prefixProd == 0) prefixProd = 1;
        }

        int suffixProd = 1;
        for(int i = n - 1 ; i >= 0 ; i--){
            suffixProd *= nums[i];

            if(suffixProd > maxi){
                maxi = suffixProd;
            }

            if(suffixProd == 0) suffixProd = 1;
        }

        return maxi;
    }
};