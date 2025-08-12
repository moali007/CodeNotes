class Solution {
public:
    const int MOD = 1e9 + 7;

    int power(int base, int exp) {
        int result = 1;
        for (int i = 0; i < exp; ++i) {
            result *= base;
        }
        return result;
    }

    int solve(int i, int sum, int x, const vector<int>& nums, vector<vector<int>>& dp) {
        if (sum == 0) return 1;
        if (sum < 0 || i >= nums.size()) return 0;

        if (dp[i][sum] != -1) return dp[i][sum];

        int pick = 0;
        int p = power(nums[i], x);
        if (sum >= p) {
            pick = solve(i + 1, sum - p, x, nums, dp);
        }

        int skip = solve(i + 1, sum, x, nums, dp);

        return dp[i][sum] = (pick + skip) % MOD;
    }

    int numberOfWays(int n, int x) {
        vector<int> nums;
        int i = 1;
        while (true) {
            int p = power(i, x);
            if (p > n) break;
            nums.push_back(i);
            ++i;
        }

        vector<vector<int>> dp(nums.size(), vector<int>(n + 1, -1));
        return solve(0, n, x, nums, dp);
    }
};
