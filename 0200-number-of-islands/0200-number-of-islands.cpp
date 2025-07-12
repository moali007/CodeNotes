class Solution {
public:
    int n,m;
    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, 1, 0, -1};

    void bfs(int r, int c, vector<vector<int>> &vis, vector<vector<char>>& grid){
        vis[r][c] = 1;
        queue<pair<int, int>> q;
        q.push({r, c});

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int drow = row + delrow[i];
                int dcol = col + delcol[i];

                if(drow >= 0 && drow < n && dcol >= 0 && dcol < m 
                   && vis[drow][dcol] == 0 && grid[drow][dcol] == '1'){
                    vis[drow][dcol] = 1;
                    q.push({drow, dcol});
                }
            }
        }
    }

    void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<char>>& grid){
        vis[r][c] = 1;

        for(int i = 0; i < 4; i++){
            int drow = r + delrow[i];
            int dcol = c + delcol[i];

            if(drow >= 0 && drow < n && dcol >= 0 && dcol < m 
                && vis[drow][dcol] == 0 && grid[drow][dcol] == '1'){
                    
                    dfs(drow, dcol, vis, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;
        
        for(int row = 0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col] && grid[row][col] == '1'){

                    // bfs(row,col,vis,grid);
                    // count++;
                    dfs(row, col, vis, grid);
                    count++;

                }
            }
        }
        return count;
    }
};