class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);

        sort(rbegin(nums), rend(nums));

        int sum = 0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            sum += nums[i];
            ans.push_back(nums[i]);

            int remSum = total - sum;

            if(sum > remSum) break;
        }

        return ans;
    }
};