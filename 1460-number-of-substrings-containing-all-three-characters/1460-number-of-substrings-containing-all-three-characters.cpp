class Solution {
public:
    
    int f(string &s, int k){
        int n = s.length();

        int i=0, j=0;
        int cnt = 0;
        unordered_map<char, int> mp;

        while(j < n){
            mp[s[j]]++;

            while(mp.size() > k){
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }

            cnt += (j-i+1);
            j++;
        }

        return cnt;
    }

    int numberOfSubstrings(string s) {
        
        return f(s, 3) - f(s, 2);
    }
};