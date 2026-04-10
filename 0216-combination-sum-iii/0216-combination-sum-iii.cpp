class Solution {
public:
    vector<vector<int>> ans;

    void solve(int i, vector<int> &arr, int k, int n, vector<int> &v){
        if(n == 0 and v.size() == k){
            ans.push_back(v);
            return;
        }

        if(i == arr.size()){
            return;
        }

        //nt
        solve(i+1, arr, k, n, v);

        //t
        if(arr[i] <= n){
            v.push_back(arr[i]);
            solve(i+1, arr, k, n - arr[i], v);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> v;
        solve(0, arr, k, n, v);

        return ans;
    }
};