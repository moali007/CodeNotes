class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        int i = 0, j = 0;
        int maxlen = 0;

        unordered_map<char, int> mp;

        while(j < n){
            if(!mp.empty() && mp.find(s[j]) != mp.end()){
                if(mp[s[j]] >= i){
                    i = mp[s[j]] + 1;
                }
            }

            mp[s[j]] = j;
            maxlen = max(maxlen, j - i + 1);
            j++;
        }
        return maxlen;
    }
};