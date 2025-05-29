class Solution {
public:
    
    unordered_map<int, vector<int>> findAdjList(vector<vector<int>>& edges){

        unordered_map<int, vector<int>> adj;

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return adj;
    }

    void dfs(int node, int val, vector<bool>&vis, vector<int>&mark, unordered_map<int, vector<int>>&adj){
        vis[node] = true;
        mark[node] = val;

        for(auto it : adj[node]){
            if(!vis[it]){ 
                dfs(it, !val, vis, mark, adj); //this dfs will mark the neighbours of current node with alternate of what current node was marked
            }
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int N = edges1.size() + 1; //number of nodes in tree 1
        int M = edges2.size() + 1; ////number of nodes in tree 2

        unordered_map<int, vector<int>> adj1 = findAdjList(edges1); //adj1 = adjacency List of tree1
        unordered_map<int, vector<int>> adj2 = findAdjList(edges2); //adj2 = adjacency List of tree2

        vector<int> mark(N, -1);
        vector<bool> vis(N, false);
        int zero = 0; //marking the starting node of tree1 with 0
        for(int i=0;i<N;i++){
            if(!vis[i]){
                dfs(i, zero, vis, mark, adj1);
            }
        }

        int zeroCnt = 0;
        int oneCnt = 0;

        for(int i=0;i<N;i++){
            if(mark[i] == 0) zeroCnt++;
            else oneCnt++;
        }

        vector<int> result1(N);

        for(int i=0;i<N;i++){
            if(mark[i] == 0) result1[i] = zeroCnt;
            else result1[i] = oneCnt;
        }

        //similarly for tree2, I am marking the connecting node with 1
        vector<int> mark1(M, -1);
        vector<bool> vis1(M, false);
        int one = 1;
        for(int i=0;i<M;i++){
            if(!vis1[i]){
                dfs(i, one, vis1, mark1, adj2);
            }
        }

        zeroCnt = 0;
        oneCnt = 0;

        for(int i=0;i<M;i++){
            if(mark1[i] == 0) zeroCnt++;
            else oneCnt++;
        }

        int maxValue_In_tree2 = max(zeroCnt, oneCnt);

        for(int i=0;i<N;i++){
            result1[i] += maxValue_In_tree2;
        }


        return result1;
    }
};