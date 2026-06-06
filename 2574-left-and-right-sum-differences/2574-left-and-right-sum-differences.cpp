class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n);
        int ls=0;
        leftSum[0] = 0;
        for(int i=1;i<n;i++){
            ls += nums[i-1];
            leftSum[i] = ls;
        }
        
        vector<int> rightSum(n);
        rightSum[n-1] = 0;
        int rs = 0;

        for(int i=n-2;i>=0;i--){
            rs += nums[i+1];
            rightSum[i] = rs;
        }
        
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = abs(leftSum[i] - rightSum[i]);
        }

        return ans;
        
    }
};