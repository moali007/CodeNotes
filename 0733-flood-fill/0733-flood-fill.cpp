class Solution {
public:
    
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};
    int n,m;
    void dfs(int row, int col, vector<vector<int>>&vis, vector<vector<int>>& image, int color, int initialColor){
        vis[row][col] = 1;
        image[row][col] = color;

        for(int i = 0; i < 4; i++){
                int drow = row + dr[i];
                int dcol = col + dc[i];

                if(drow>=0 and drow<n and dcol>=0 and dcol<m and vis[drow][dcol] == 0
                     and image[drow][dcol] == initialColor){

                    dfs(drow, dcol, vis, image, color, initialColor);
                }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size();
        m = image[0].size();

        int initialColor = image[sr][sc];
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        dfs(sr, sc, vis, image, color, initialColor);

        return image;
        
    }
};