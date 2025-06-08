class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = x.size();

        unordered_map<int, vector<int>> mp;

        for(int i=0;i<n;i++){
            mp[x[i]].push_back(i);
        }

        if(mp.size() < 3) return -1;

        vector<int> maxVal;

        for(auto it : mp){
            vector<int> v = it.second;
            int val = INT_MIN;
            for(int it : v){
                val = max(val, y[it]);
            }
            maxVal.push_back(val);
        }

        sort(maxVal.rbegin(), maxVal.rend());

        int sum = 0;
        for(int i=0;i<3;i++){
            sum += maxVal[i];
        }

        return sum;
        
    }
};