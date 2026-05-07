class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, vector<int>> mp; //{num - {indexes at which num is present}}
        for(int i = 0; i < n; i++){
            mp[arr[i]].push_back(i);
        }

        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0);
        vis[0] = true;

        int steps = 0;

        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i < size; i++){
                int curr_idx = q.front();
                q.pop();

                if(curr_idx == n-1) return steps;

                int left = curr_idx - 1;
                int right = curr_idx + 1;

                if(left >= 0 and !vis[left]){
                    q.push(left);
                    vis[left] = true;
                }

                if(right < n and !vis[right]){
                    q.push(right);
                    vis[right] = true;
                }

                for(int idx : mp[arr[curr_idx]]){
                    if(!vis[idx]){
                        q.push(idx);
                        vis[idx] == true;
                    }
                }

                mp.erase(arr[curr_idx]);
            }

            steps++;
        }

        return -1;
    }
};