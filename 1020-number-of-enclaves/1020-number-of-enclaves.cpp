class Solution {
public:
    int n, m;
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};

    void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<int>> &grid){
        vis[i][j] = true;
        // grid[i][j] = 0;

        for(int k = 0; k < 4; k++){
            int r = i + dr[k];
            int c = j + dc[k];

            if(r >= 0 and r < n and c >= 0 and c < m and grid[r][c] == 1 and !vis[r][c]){
                dfs(r, c, vis, grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<bool>> vis(n , vector<bool>(m, false));

        for(int j = 0; j < m; j++){
            if(grid[0][j] == 1 and !vis[0][j]){
                dfs(0, j, vis, grid);
            }

            if(grid[n-1][j] == 1 and !vis[n-1][j]){
                dfs(n-1, j, vis, grid);
            }
        }

        for(int i = 0; i < n; i++){
            if(grid[i][0] == 1 and !vis[i][0]){
                dfs(i, 0, vis, grid);
            }

            if(grid[i][m-1] == 1 and !vis[i][m-1]){
                dfs(i, m-1, vis, grid);
            }
        }

        int cnt = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 and vis[i][j] == false)
                   cnt++;
            }
        }

        return cnt;


    }
};