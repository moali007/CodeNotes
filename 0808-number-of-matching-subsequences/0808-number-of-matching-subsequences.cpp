class Solution {
public:
    int n;
    //returns true if s1 is a subsequence of s2
    bool checkSubsequence(string s1, string &s2){
        int m = s1.length();

        int i=0,j=0;
        while(i < m && j < n){
            if(s1[i] == s2[j]){
                i++,j++;
            }
            else j++;
        }

        return i == m;
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        n = s.length();
        
        unordered_map<string, int> mp;
        for(string word : words){
            mp[word]++;
        }

        int cnt = 0;

        for(auto it : mp){
            if(checkSubsequence(it.first, s) == true){
                cnt += it.second;
            }
        }

        return cnt;
    }
};