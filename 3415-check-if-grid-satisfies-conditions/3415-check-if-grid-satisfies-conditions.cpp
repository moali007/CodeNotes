class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                int currVal = grid[i][j];
                int below = currVal, right = currVal + 1;

                if(i+1 < n) below = grid[i+1][j];
                if(j+1 < m) right = grid[i][j+1];

                if(currVal != below || currVal == right) return false;
            }
        }

        return true;
    }
};