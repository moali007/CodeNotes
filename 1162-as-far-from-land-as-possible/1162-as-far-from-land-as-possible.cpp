class Solution {
public:
    // Multi-source BFS from LAND (1)
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;

        // Step 1: Push all land
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                }
            }
        }

        // Edge cases
        if(q.empty() || q.size() == n*n) return -1;

        int dist = -1;
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};

        // Step 2: BFS
        while(!q.empty()){
            int sz = q.size();
            dist++;

            while(sz--){
                auto [r, c] = q.front();
                q.pop();

                for(int i = 0; i < 4; i++){
                    int nr = r + drow[i];
                    int nc = c + dcol[i];

                    if(nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 0){
                        grid[nr][nc] = 1; // mark visited
                        q.push({nr, nc});
                    }
                }
            }
        }

        return dist;
    }
};