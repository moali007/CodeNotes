class Solution {
public:
    int n;
    bool solve(int i, vector<int> &arr, vector<int>& vis){
        if(i >= n || i < 0) return false;

        if(vis[i] == 1) return false;
        
        if(arr[i] == 0) return true;

        vis[i] = 1;

        bool op1 = solve(i + arr[i], arr, vis);
        bool op2 = solve(i - arr[i], arr, vis);

        return op1 || op2;
    }

    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        
        vector<int> vis(n, 0);
        return solve(start, arr, vis);
    }
};