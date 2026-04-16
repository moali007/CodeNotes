class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;
        for(auto q : queries){
            int idx = q;
            int num = nums[idx];

            vector<int>& v = mp[num];
            int m = v.size();
            if(m == 1){
                ans.push_back(-1);
                continue;
            }else{
                // binary search
                int pos = lower_bound(v.begin(), v.end(), idx) - v.begin();

                //neighbors
                int left = v[(pos - 1 + m) % m];
                int right = v[(pos + 1) % m];

                // distances
                int d1 = abs(idx - left);
                int d2 = n - d1;
                int d3 = abs(idx - right);
                int d4 = n - d3;

                int dist1 = min(d1, d2);
                int dist2 = min(d3, d4);

                ans.push_back(min(dist1, dist2));
            }
        }

        return ans;
    }
};