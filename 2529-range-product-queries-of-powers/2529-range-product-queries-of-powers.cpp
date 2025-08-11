class Solution {
public:
    int mod = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;

        for(int i=0;i<32;i++){
            if((n & (1 << i))!= 0){
                powers.push_back(1 << i);
            }
        }

        // int n = queries.size();
        vector<int> ans;

        for(auto it : queries){
            int left = it[0];
            int right = it[1];
            
            long long p = 1;
            for(int i=left;i<=right;i++){
                p = (p % mod * powers[i] % mod) % mod;
            }
            ans.push_back(p);
        }



        return ans;
    }
};