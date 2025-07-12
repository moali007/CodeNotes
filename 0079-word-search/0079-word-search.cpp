class Solution {
public:
    int m,n;
    vector<int> delrow = {-1,0,1,0};
    vector<int> delcol = {0,1,0,-1};
    // vector<vector<int>> dirs{{-1,0}, {0,1}, {1,0}, {0,-1}};
    bool find(int row, int col, int idx, string &word, vector<vector<char>>& board){
        if(idx == word.length()){
            return true;
        }

        if(row<0 || col<0 || row>=m || col>=n || board[row][col] == '$' || board[row][col] != word[idx]){
            return false;
        }

        //yaha aa gae matlab board[row][col] == word[idx] --> visit board[row][col]

        //do
        char temp = board[row][col];
        board[row][col] = '$';

        for(int i=0;i<4;i++){
            int drow = row + delrow[i];
            int dcol = col + delcol[i];

            if(find(drow, dcol, idx+1, word, board) == true){
                return true;
            }
        }

        //undo
        board[row][col] = temp;
        return false;
    }

    

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        // int delrow[] = {-1,0,1,0};
        // int delcol[] = {0,1,0,-1};

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(board[i][j] == word[0] && find(i, j, 0, word, board) == true){
                    return true;
                }
            }
        }

        return false;
    }
};