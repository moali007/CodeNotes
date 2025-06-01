class Solution {
public:
    int n;

    bool isPallindrome(string &s, int l, int r){
        while(l < r){
            if(s[l] != s[r]) return false;
            else{
                l++,r--;
            }
        }
        return true;
    }

    void f(int idx, string &s, vector<string> &curr, vector<vector<string>> &result){
        if(idx == n){
            result.push_back(curr);
            return;
        }

        for(int i=idx;i<n;i++){
            if(isPallindrome(s, idx, i)){
                curr.push_back(s.substr(idx, i-idx+1));

                f(i+1, s, curr, result);

                curr.pop_back();
            }
        }
    } 
    
    vector<vector<string>> partition(string s) {
        n = s.length();
        vector<vector<string>> result;
        vector<string> curr;

        f(0, s, curr, result);

        return result;
    }
};