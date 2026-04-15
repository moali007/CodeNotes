class Solution {
public:
    int n,m;
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, 1, 0, -1};
    void dfs(int r, int c, vector<vector<int>>&vis, vector<vector<int>>&grid, int &perimeter){
        vis[r][c] = 1;

        for(int i=0;i<4;i++){
            int dr = r + drow[i];
            int dc = c + dcol[i];

            if(dr < 0 || dr >= n || dc < 0 || dc >= m || grid[dr][dc] == 0){
                perimeter++;
            }

            if(dr>=0 and dr<n and dc>=0 and dc<m and vis[dr][dc] == 0 and grid[dr][dc] == 1){
                dfs(dr,dc,vis,grid,perimeter);
            }
        }
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int r=-1, c=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    r = i;
                    c = j;
                    break;
                }
            }
        }

        int perimeter = 0;

        dfs(r, c, vis, grid, perimeter);

        return perimeter;
    }
};