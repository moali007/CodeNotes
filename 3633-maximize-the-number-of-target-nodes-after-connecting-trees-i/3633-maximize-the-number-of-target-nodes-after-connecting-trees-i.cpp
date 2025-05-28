class Solution {
public:

    int bfs(int currNode, unordered_map<int, vector<int>> &adj, int d, int N){
        queue<pair<int, int>> q;
        q.push({currNode, 0});
        vector<bool> vis(N, false);
        vis[currNode] = true;

        int count = 0;
        
        while(!q.empty()){
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();

            if(dist > d){
                continue;
            }
            count++;
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = true;
                    q.push({it, dist+1});
                }
            }
        }

        return count;
    }
    
    vector<int> findCount(vector<vector<int>>& edges, int d){
        int N = edges.size() + 1;

        //adjacency list
        unordered_map<int, vector<int>> adj;
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> ans(N);
        for(int i=0;i<N;i++){
            ans[i] = bfs(i, adj, d, N);
        }

        return ans;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int N = edges1.size() + 1; //number of nodes in tree 1

        vector<int> result1 = findCount(edges1, k); //stores targetNode count from each node in tree1 within distance <= k
        vector<int> result2 = findCount(edges2, k-1); //stores targetNode count from each node in tree2 within distance <= k-1

        int maxNodesCnt = *max_element(result2.begin(), result2.end());

        for(int i=0;i<result1.size();i++){
            result1[i] += maxNodesCnt;
        }

        return result1;
    }
};