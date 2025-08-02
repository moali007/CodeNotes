class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
        int mini = 1e9;
        unordered_map<int, int> mp;
        for(int i=0;i<b1.size();i++){
            mp[b1[i]]++;
            mp[b2[i]]--;

            mini = min(mini, min(b1[i], b2[i]));
        }


        vector<int> arr;
        for(auto it : mp){
            int u = it.first;
            int v = it.second;
            if(it.second % 2 == 1) return -1;

            for(int i=0;i < abs(v/2);i++){
                arr.push_back(u);
            }
        }

        long long cost = 0;

        sort(arr.begin(), arr.end());

        for(int i=0;i<arr.size()/2;i++){
            cost += min(arr[i], 2*mini);
        }

        return cost;
    }
};