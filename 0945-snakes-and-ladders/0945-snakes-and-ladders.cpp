class Solution {
public:
    int n;
    
    pair<int, int> getCoord(int num){

        int RT = (num - 1)/n; //row from top 
        int RB = n - 1 - RT;

        int col = (num - 1)%n;

        if((n%2==0 && RB%2==0) || (n%2==1 && RB%2==1)){
            col = n - 1 - col;
        }

        return make_pair(RB, col);

    }

    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();

        queue<int> q;
        int steps = 0;
        q.push(1);
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vis[n-1][0] = true;

        while(!q.empty()){
            int N = q.size();

            while(N--){
                int x = q.front(); q.pop();

                if(x == n*n) return steps;

                for(int i=1;i<=6;i++){
                    int val = x + i;

                    if(val > n*n){
                        break;
                    }

                    pair<int, int> coord = getCoord(val);
                    int r = coord.first;
                    int c = coord.second;

                    if(vis[r][c] == true){
                        continue;
                    }

                    vis[r][c] = true;

                    if(board[r][c] == -1){
                        q.push(val);
                    }
                    else{
                        q.push(board[r][c]);
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};