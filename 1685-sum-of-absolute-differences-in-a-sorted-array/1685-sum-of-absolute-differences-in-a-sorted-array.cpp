class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();

        vector<int> preSum(n, 0);
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            preSum[i] = sum;
        }

        vector<int> ans(n, 0);

        for(int i = 0; i < n; i++){
            int leftSum = preSum[i] - nums[i];
            int leftLength = i;
            int leftDiff = abs(leftSum - leftLength * nums[i]);

            int rightSum = preSum[n-1] - nums[i] - leftSum;
            int rightLength = n - i - 1;
            int rightDiff = abs(rightSum - rightLength * nums[i]);

            ans[i] = leftDiff + rightDiff;
        }

        return ans;
    }
};