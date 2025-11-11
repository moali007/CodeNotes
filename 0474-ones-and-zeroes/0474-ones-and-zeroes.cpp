class Solution {
public:

    void convertStrsToNumStrs(vector<string>& strs,vector<pair<int,int>> &numStrs){
        for(auto str:strs){
            int zeros=0,ones=0;
            for(auto ch:str){
                if(ch=='0') zeros++;
                else ones++;
            }
            numStrs.push_back({zeros,ones});
        }
    }

    int recSolve(vector<pair<int,int>> &numStrs,int i,int m,int n){
        //bc
        if(i==numStrs.size()) return 0;

        int zeros=numStrs[i].first;
        int ones=numStrs[i].second;
        int include=0,exclude=0;
        if(m-zeros >= 0 && n-ones >= 0)
        include = 1 + recSolve(numStrs,i+1,m-zeros,n-ones);
        exclude = recSolve(numStrs,i+1,m,n);

        return max(include,exclude);

    }

    int memSolve(vector<pair<int,int>> &numStrs,int i,int m,int n,vector<vector<vector<int>>> &dp){
        //bc
        if(i==numStrs.size()) return 0;
        //step 3
        if(dp[i][m][n] != -1){
            return dp[i][m][n];
        }
        
        int zeros=numStrs[i].first;
        int ones=numStrs[i].second;
        int include=0,exclude=0;
        if(m-zeros >= 0 && n-ones >= 0)
        include = 1 + memSolve(numStrs,i+1,m-zeros,n-ones,dp);
        exclude = memSolve(numStrs,i+1,m,n,dp);

        return dp[i][m][n] = max(include,exclude);

    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> numStrs; //{no of 0's,no of 1's}
        convertStrsToNumStrs(strs,numStrs);

        // return recSolve(numStrs,0,m,n);
        //memoisation
        //step 1
        vector<vector<vector<int>>> dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return memSolve(numStrs,0,m,n,dp);
    }
};