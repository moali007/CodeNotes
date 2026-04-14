class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();

        unordered_map<char, int> mp;
        for(char ch : s){
            mp[ch]++;
        }

        bool hasodd = false;

        int len = 0;
        for(auto m : mp){
            if(m.second % 2 == 0){
                len += m.second;
            }else{
                len += (m.second - 1);
                hasodd = true;
            }
            
        }

        if(hasodd) len += 1;
        return len;
    }
};