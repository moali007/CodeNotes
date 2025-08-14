class Solution {
public:
    int numSplits(string s) {
        int n = s.length();
        
        int cnt = 0;

        unordered_map<char, int> mp1;
        for(char ch : s){
            mp1[ch]++;
        }

        unordered_map<char, int> mp2;
        for(char ch : s){
            mp2[ch]++;
            mp1[ch]--;
            if(mp1[ch] == 0) mp1.erase(ch);

            if(mp1.size() == mp2.size()) cnt++;
        }

        return cnt;
    }
};