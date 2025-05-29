class Solution {
public:
    
    void dfs(int node, unordered_map<int, vector<int>> &adj, vector<bool> &vis){
        vis[node] = true;

        for(auto it : adj[node]){
            if(!vis[it])
               dfs(it, adj, vis);
        }
    }

    int findCircleNum(vector<vector<int>>& mat) {
        int n = mat.size();

        unordered_map<int, vector<int>> adj;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> vis(n, false);
        int count = 0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i, adj, vis);
                count++;
            }
        }

        return count;
        
    }
};