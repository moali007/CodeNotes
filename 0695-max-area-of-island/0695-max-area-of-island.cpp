class Solution {
public:
    int n, m;
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, 1, 0, -1};
    
    void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<int>>& grid, int &cnt){
        vis[r][c] = 1;
        cnt++;

        for(int i=0;i<4;i++){
            int dr = r + drow[i];
            int dc = c + dcol[i];

            if(dr>=0 and dr<n and dc>=0 and dc<m and vis[dr][dc] == 0 and grid[dr][dc] == 1){
                dfs(dr, dc, vis, grid, cnt);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int maxArea = 0;
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    dfs(i, j, vis, grid, cnt);
                    maxArea = max(maxArea, cnt);
                    cnt = 0;
                }
            }
        }

        return maxArea;
    }
};