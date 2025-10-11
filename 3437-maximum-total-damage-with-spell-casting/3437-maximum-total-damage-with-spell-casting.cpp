class Solution {
public:
    int n;
    unordered_map<int, int> mp;

    long long solve(int i, vector<int> &power, vector<long long> &dp){
        if(i >= n){
            return 0;
        }

        if(dp[i] != -1) return dp[i];

        long long skip = solve(i+1, power, dp);

        long long take = (long long)power[i] * mp[power[i]];
        int j = lower_bound(power.begin() + i + 1, power.end(), power[i] + 3) - power.begin();

        take += solve(j, power, dp);

        return dp[i] = max(skip, take);
    }
    
    long long maximumTotalDamage(vector<int>& power) {
        n = power.size();
        for(int p : power){
            mp[p]++;
        }

        sort(power.begin(), power.end());
        
        vector<long long> dp(n+1, -1);
        return solve(0, power, dp);
    }
};