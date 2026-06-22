class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> mp;

        for(char ch : s){
            mp[ch]++;
        }

        unordered_map<char, int> mp1;

        for(char ch : target){
            mp1[ch]++;
        }

        int cnt = 1e9;

        for(auto it : mp1){
            char ch = it.first;
            if(mp.find(ch) == mp.end()){
                return 0;
            }

            cnt = min(cnt, mp[ch] / mp1[ch]);
        }

        return cnt;
    }
};