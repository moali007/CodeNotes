class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> oneRow; //contains no. of 1s in all rows
        vector<int> zeroRow; //contains no. of zeros in each row

        for(int row=0;row<n;row++){
            int one=0;
            for(int col=0;col<m;col++){
                if(grid[row][col] == 1) one++;
            }
            oneRow.push_back(one);
            zeroRow.push_back(m-one);
        }


        vector<int> oneCol; //contains no. of 1s in each column
        vector<int> zeroCol; //contains no. of zeros in each column

        for(int col=0;col<m;col++){
            int one=0;
            for(int row=0;row<n;row++){
                if(grid[row][col] == 1) one++;
            }
            oneCol.push_back(one);
            zeroCol.push_back(n-one);
        }


        vector<vector<int>> diff(n, vector<int>(m, 0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                diff[i][j] = oneRow[i] + oneCol[j] - zeroRow[i] - zeroCol[j];
  
            }
        }

        return diff;

    }
};