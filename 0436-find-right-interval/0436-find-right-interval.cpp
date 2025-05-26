class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();

        unordered_map<int, int> mp; //{starti, index}
        vector<int> starti(n);

        for(int i=0;i<n;i++){
            starti[i] = intervals[i][0];
            mp[starti[i]] = i;
        }

        sort(starti.begin(), starti.end());
        vector<int> ans;

        for(auto it : intervals){
            int endi = it[1];
            int idx = lower_bound(starti.begin(), starti.end(), endi) - starti.begin();
            if(idx >= n){
                ans.push_back(-1);
            }
            else{
                int starti_val = starti[idx];
                ans.push_back(mp[starti_val]);
            }
        }
        return ans;
    }
};