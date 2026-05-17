class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        vector<bool> vis(n, false);
        queue<int> q;
        q.push(start);
        vis[start] = true;

        while(!q.empty()){
            int idx = q.front(); q.pop();

            if(arr[idx] == 0) return true;

            int left = idx - arr[idx];
            int right = idx + arr[idx];

            if(left >= 0 and !vis[left]){
                vis[left] = true;
                q.push(left);
            }

            if(right < n and !vis[right]){
                vis[right] = true;
                q.push(right);
            }
        }

        return false;
    }
};