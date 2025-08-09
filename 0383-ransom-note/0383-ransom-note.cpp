class Solution {
public:
    bool canConstruct(string r, string m) {
        unordered_map<char, int> mp;

        for(char ch : m){
            mp[ch]++;
        }

        for(char ch : r){
            if(mp.find(ch) == mp.end()) return false;

            mp[ch]--;
            if(mp[ch] == 0) mp.erase(ch);
        }

        return true;
    }
};