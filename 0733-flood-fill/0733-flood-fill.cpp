class Solution {
public:
    int n, m;
    vector<int> delrow =  {-1,0,1,0};
    vector<int> delcol = {0,1,0,-1};
    
    void dfs(int r, int c, int iniColor, int color, vector<vector<bool>>& vis, vector<vector<int>>& image){
        vis[r][c] = true;
        image[r][c] = color;

        for(int i = 0; i < 4; i++){
            int row = r + delrow[i];
            int col = c + delcol[i];

            if(row >= 0 and row < n and col >= 0 and col < m and image[row][col] == iniColor and !vis[row][col]){
                dfs(row, col, iniColor, color, vis, image);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size();
        m = image[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int iniColor = image[sr][sc];

        dfs(sr, sc, iniColor, color, vis, image);

        return image;

    }
};