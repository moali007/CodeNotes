class Solution {
public:
    const int MOD = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        for(auto q : queries){
            //q = [l, r, k, v]
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];

            for(int idx = l; idx <= r; idx += k){
                long long temp = nums[idx];
                nums[idx] = (temp * v) % (MOD);
            }
        }

        int xr = 0;
        for(int i = 0; i < n; i++){
            xr = xr ^ nums[i];
        }

        return xr;
    }
};