class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans(m-k+1, vector<int>(n-k+1, 0));
        
        for(int i = 0; i <= m-k; i++){
            for(int j = 0; j <= n-k; j++){

                set<int> unique;

                for(int x = i; x < i+k; x++){
                    for(int y = j; y < j+k; y++){

                        unique.insert(grid[x][y]);
                    }
                }

                if(unique.size() <= 1) ans[i][j] = 0;
                else{
                    vector<int> vec;
                    for(auto it : unique){
                        vec.push_back(it);
                    }
                    //vec will be sorted, just calculate minDifference of adjacent elements
                    int minDiff = INT_MAX;
                    for(int z = 1; z < vec.size(); z++){
                        minDiff = min(minDiff, vec[z]-vec[z-1]);
                    }

                    ans[i][j] = minDiff;
                }
            }
        }

        return ans;

    }
};