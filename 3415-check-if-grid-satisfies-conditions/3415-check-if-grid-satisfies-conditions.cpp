class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                int currVal = grid[i][j];
                int below = currVal, right = currVal + 1;
                //below ko currVal iss lie rakha coz agar below na ho tab bhi true ho
                //similarly right ko aisa value dia jo currVal ke barabar na ho

                if(i+1 < n) below = grid[i+1][j];
                if(j+1 < m) right = grid[i][j+1];

                if(currVal != below || currVal == right) return false;
            }
        }

        return true;
    }
};