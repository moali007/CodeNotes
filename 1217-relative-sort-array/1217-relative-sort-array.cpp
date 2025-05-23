class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();

        map<int, int> mp;
        for(int i=0;i<n;i++){
            mp[arr1[i]]++;
        }

        vector<int> ans;
        for(int i=0;i<m;i++){
            int num = arr2[i];
            int freq = mp[arr2[i]];

            while(freq--){
                ans.push_back(num);
            }

            mp.erase(num);
        }

        for(auto it : mp){
            while(it.second--){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};