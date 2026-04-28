class Solution {
public:
    int minMoves2(vector<int>& nums, int x) {
        sort(nums.begin(), nums.end());

        int median = nums[nums.size() / 2];

        int cnt = 0;
        for(auto num : nums){
            cnt += abs(num - median) / x;
        }

        return cnt;
    }

    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;

        for(auto &row : grid){
            for(auto val : row){
                nums.push_back(val);
            }
        }

        // feasibility check
        int rem = nums[0] % x;
        for(auto num : nums){
            if(num % x != rem) return -1;
        }

        return minMoves2(nums, x);
    }
};