class Solution {
public:
    vector<vector<int>> ans;
    int n;

    void solve(int i, vector<int>& candidates, int target, vector<int> &v){
        if(target == 0){
            ans.push_back(v);
            return;
        }

        if(i == n){
            return;
        }

        //nt
        solve(i+1, candidates, target, v);

        //t
        if(candidates[i] <= target){
            v.push_back(candidates[i]);
            solve(i, candidates, target - candidates[i], v);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();

        vector<int> v;
        solve(0, candidates, target, v);

        return ans;
    }
};