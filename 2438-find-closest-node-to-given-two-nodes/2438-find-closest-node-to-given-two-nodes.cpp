class Solution {
public:
    
    void dfs(int node, int d, vector<int>& edges, vector<int> &dist, vector<bool> &vis){
        vis[node] = true;
        dist[node] = d;

        int v = edges[node];

        if(v != -1 && !vis[v]){
            dfs(v, d+1, edges, dist, vis);
        }

    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        vector<int> dist_1(n, 1e7);
        vector<int> dist_2(n, 1e7);
        vector<bool> vis1(n, false);
        vector<bool> vis2(n, false);

        dfs(node1, 0, edges, dist_1, vis1);
        dfs(node2, 0, edges, dist_2, vis2);

        int minDistNode = -1;
        int minDistTillNow = 1e7;

        for(int i=0;i<n;i++){

            int maxD = max(dist_1[i], dist_2[i]);

            if(minDistTillNow > maxD){
                minDistTillNow  = maxD;
                minDistNode = i;
            }
        }

        return minDistNode;
    }
};