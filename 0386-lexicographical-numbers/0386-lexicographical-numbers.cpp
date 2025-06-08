class Solution {
public:
    
    void solve(int start,int n,vector<int> &result){
        if(start > n){
            return;
        }
        result.push_back(start);

        for(int append=0;append<=9;append++){
            int newNum = start*10 + append;

            if(newNum > n){
                return;
            }
            solve(newNum,n,result);
        }
    }
    
    vector<int> lexicalOrder(int n) {
        vector<int> result;

        for(int startNum=1;startNum<=9;startNum++){
            solve(startNum,n,result);
        }
        return result;
    }
};