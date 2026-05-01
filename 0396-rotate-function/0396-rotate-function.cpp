class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        //F(0)
        int F_0 = 0;
        for(int i = 0; i < n; i++){
            F_0 += (i * nums[i]);
            sum += nums[i];
        }

        int maxi = F_0;

        int F = F_0;
        for(int k = 0; k <= n-1; k++){
            int new_F = F + sum - n * nums[n-1-k];
            maxi = max(maxi, new_F);
            F = new_F;
        }

        return maxi;

    }
};

// F(k+1) = F(k) + sum - n (last element of rotated array)
// F(k+1) = F(k) + sum - n * nums[n-1-k]