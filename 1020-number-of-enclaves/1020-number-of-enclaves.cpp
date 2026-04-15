class Solution {
public:
    int n,m;
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, 1, 0 ,-1};
    
    void dfs(int r, int c, vector<vector<int>>&vis, vector<vector<int>>&board){
        vis[r][c] = 1;

        for(int i=0;i<4;i++){
            int dr = r + drow[i];
            int dc = c + dcol[i];

            if(dr>=0 and dr<n and dc>=0 and dc<m and board[dr][dc] == 1 and vis[dr][dc] == 0){
                dfs(dr, dc, vis, board);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& board) {
        n = board.size();
        m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int j = 0; j < m; j++){
            //first row
            if(board[0][j] == 1 and vis[0][j] == 0){
                dfs(0, j, vis, board);
            }

            //last row
            if(board[n-1][j] == 1 and vis[n-1][j] == 0){
                dfs(n-1, j, vis, board);
            }
        }
        
        for(int i = 0; i < n; i++){
            //first column
            if(board[i][0] == 1 and vis[i][0] == 0){
                dfs(i, 0, vis, board);
            }

            //last column
            if(board[i][m-1] == 1 and vis[i][m-1] == 0){
                dfs(i, m-1, vis, board);
            }
        }
        
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 1 and vis[i][j] == 0){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};