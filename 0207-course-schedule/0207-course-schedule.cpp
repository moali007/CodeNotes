class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
         unordered_map<int, vector<int>> adj;
        
        for(auto it : prerequisites){
            int u = it[1];
            int v = it[0];
            
            adj[u].push_back(v);
        }
        
        vector<int> indegree(n, 0);
        
        for(int i=0;i<n;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        int topo = 0;
        
        queue<int> q;
        
        for(int i=0;i<n;i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            // topo.push_back(node);
            topo++;
            
            for(auto it : adj[node]){
                indegree[it]--;
                
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        return topo == n;
    }
};