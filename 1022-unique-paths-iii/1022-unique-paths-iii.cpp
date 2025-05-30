class Solution {
public:
    int n,m;
    int nonObstaclesCount;
    int result;
    vector<vector<int>> dirs{{-1,0}, {0,1}, {1,0}, {0,-1}};
    
    void solve(int i, int j, int cnt, vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j] == -1){
            return;
        }

        if(grid[i][j] == 2){
            if(cnt == nonObstaclesCount)
                result++;
            return;
        }

        //yaha pohoch gai that means grid[i][j] == 0, can walk
        //mark - Do
        grid[i][j] = -1;

        for(auto &d : dirs){
            int nrow = i + d[0];
            int ncol = j + d[1];

            solve(nrow, ncol, cnt+1, grid);
        }
        
        //undo
        grid[i][j] = 0;
    }


    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        nonObstaclesCount = 0;
        int start_x = -1, start_y = -1;
        result = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j] == 1){
                    start_x = i;
                    start_y = j;
                }

                if(grid[i][j] == 0) nonObstaclesCount++;
            }
        }

        nonObstaclesCount += 1; //1 bhi count karo

        solve(start_x, start_y, 0, grid);
        return result;
    }
};