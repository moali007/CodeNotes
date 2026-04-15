class Solution {
public:
    int n;
    static bool myFunction(string &word1, string &word2){
        return word1.length() < word2.length();
    }

    bool isSubsequence(string &s, string &t) {
        int n = s.length();
        int m = t.length();

        int i=0,j=0;
        while(i < n && j < m){
            if(s[i]  == t[j]){
                i++,j++;
            }
            else j++;
        }

        return i == n;
    }
    
    //checks if prev is predecessor of curr (Ex - prev = "ab", curr = "acb")
    bool isPredecessor(string &prev, string &curr){
        int N = prev.length();
        int M = curr.length();

        if(N >= M || M-N != 1) return false;

        return isSubsequence(prev, curr);
    }
    
    //LIS variant
    int f(int i, int prevIdx, vector<string>& words, vector<vector<int>>&dp){
        if(i == n){
            return 0;
        }

        if(dp[i][prevIdx + 1] != -1) return dp[i][prevIdx + 1];

        //not take
        int nt = f(i+1, prevIdx, words, dp);

        //take
        int take = 0;
        if(prevIdx == -1 || isPredecessor(words[prevIdx], words[i])){
            take = 1 + f(i+1, i, words, dp);
        }

        return dp[i][prevIdx + 1] = max(take, nt);
    }

    int longestStrChain(vector<string>& words) {
        n = words.size();

        sort(words.begin(), words.end(), myFunction); //sort on basis of length
        
        vector<vector<int>> dp(n+4, vector<int>(n+4, -1));
        int prevIdx = -1;
        return f(0, prevIdx, words, dp);
    }
};