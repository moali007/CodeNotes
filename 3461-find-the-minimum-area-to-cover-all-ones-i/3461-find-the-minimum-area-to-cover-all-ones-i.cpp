class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int minRow = INT_MAX;
        int maxRow = INT_MIN;
        int minCol = INT_MAX;
        int maxCol = INT_MIN;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }

        int ht = maxRow - minRow + 1;
        int wd = maxCol - minCol + 1;

        return ht * wd;
    }
};