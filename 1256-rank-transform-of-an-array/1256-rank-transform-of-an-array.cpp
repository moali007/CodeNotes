class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();

        set<int> st(arr.begin(), arr.end());//set will remove duplicates and sort array
        vector<int> sorted;
        for(auto num : st){
            sorted.push_back(num);//sorted me sabkuch sorted hoga and no duplicates
        }

        unordered_map<int, int> mp;
        for(int i=0;i<sorted.size();i++){
            mp[sorted[i]] = i+1;
        }

        vector<int> ans(n);

        for(int i=0;i<n;i++){
            ans[i] = mp[arr[i]];
        }

        return ans;
    }
};