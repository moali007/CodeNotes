class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int initialColor = image[sr][sc];
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        vis[sr][sc] = 1;
        q.push({sr, sc});
        image[sr][sc] = color;

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int drow = r + dr[i];
                int dcol = c + dc[i];

                if(drow>=0 and drow<n and dcol>=0 and dcol<m and vis[drow][dcol] == 0
                     and image[drow][dcol] == initialColor){

                    vis[drow][dcol] = 1;
                    image[drow][dcol] = color;
                    q.push({drow, dcol});
                }
            }
        }

        return image;
        
    }
};