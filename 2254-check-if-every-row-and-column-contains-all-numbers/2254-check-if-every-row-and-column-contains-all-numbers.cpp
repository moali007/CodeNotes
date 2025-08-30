class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();

        set<pair<int, int>> row, col;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(row.find({i,matrix[i][j]})==row.end())
                    row.insert({{i,matrix[i][j]}});
                else return false;

                if(col.find({j,matrix[i][j]})==col.end())
                    col.insert({{j,matrix[i][j]}});
                else return false;
            }
        }

        return true;
    }
};