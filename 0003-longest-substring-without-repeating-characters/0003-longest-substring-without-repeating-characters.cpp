class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        unordered_map<char, int> mp;
        int i=0,j=0;
        int maxlen = 0;

        while(j < n){
            if(!mp.empty() && mp.count(s[j])){
                if(mp[s[j]] >= i){

                    i = mp[s[j]] + 1;
                }
            }

            maxlen = max(maxlen, j-i+1);
            mp[s[j]] = j;

            j++;
        }

        return maxlen;
    }
};