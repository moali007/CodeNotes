class Solution {
public:
    int mod = 1e9+7;
    int countHomogenous(string s) {
        int n = s.length();

        int i=0,j=0;
        int cnt = 0;
        unordered_map<char, int> mp;

        while(j < n){
            mp[s[j]]++;

            while(mp.size() > 1){
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }

            cnt =  (cnt%mod + (j-i+1)%mod)%mod;
            j++;
        }

        return cnt%mod;
    }
};