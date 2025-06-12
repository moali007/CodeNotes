class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();

        int maxi = -1e9;

        for(int i=0;i<n-1;i++){
            int diff = abs(nums[i] - nums[i+1]);
            maxi = max(maxi, diff);
        }

        maxi = max(maxi, abs(nums[0] - nums[n-1]));

        return maxi;
    }
};