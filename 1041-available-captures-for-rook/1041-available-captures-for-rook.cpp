class Solution {
public:
    int n,m;
    int cnt = 0;

    void attack(int r, int c, vector<vector<char>>& board){
        int rr, cc;

        //up
        rr = r - 1;
        while(rr >= 0 and board[rr][c] != 'B'){
            if(board[rr][c] == 'p'){
                cnt++;
                break;
            }
            rr--;
        }

        //down
        rr = r + 1;
        while(rr < n and board[rr][c] != 'B'){
            if(board[rr][c] == 'p'){
                cnt++;
                break;
            }
            rr++;
        }

        //left
        cc = c - 1;
        while(cc >= 0 and board[r][cc] != 'B'){
            if(board[r][cc] == 'p'){
                cnt++;
                break;
            }
            cc--;
        }

        //right
        cc = c + 1;
        while(cc < m and board[r][cc] != 'B'){
            if(board[r][cc] == 'p'){
                cnt++;
                break;
            }
            cc++;
        }
    }
     
    

    int numRookCaptures(vector<vector<char>>& board) {
        n = board.size(); //row
        m = board[0].size(); //col

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(board[i][j] == 'R'){
                    attack(i, j, board);
                }
            }
        }

        return cnt;
    }
};

//R = rook
//p = pawn
//B = bishop
//'.' = empty