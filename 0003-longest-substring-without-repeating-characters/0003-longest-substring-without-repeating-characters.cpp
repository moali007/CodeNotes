class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        int i = 0, j = 0;
        int maxi = 0;
        unordered_map<char, int> mp; //{char, idx}

        while(j < n){
            if(!mp.empty() and mp.count(s[j]) and mp[s[j]] >= i){
                i = mp[s[j]] + 1;
            }
            
            mp[s[j]] = j;
            maxi = max(maxi, j-i+1);
            j++;
        }

        return maxi;
    }
};
