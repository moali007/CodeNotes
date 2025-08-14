class Solution {
public:
    int numSplits(string s) {
        int n = s.length();
        
        int cnt = 0;

        // unordered_map<char, int> mp1;
        vector<int> mp1(26, 0);
        for(char ch : s){
            mp1[ch - 'a']++;
        }

        // unordered_map<char, int> mp2;
        vector<int> mp2(26, 0);
        for(char ch : s){
            mp2[ch - 'a']++;
            mp1[ch - 'a']--;
            // if(mp1[ch] == 0) mp1.erase(ch);
            int a = 0, b = 0;
            for(int i=0;i<26;i++){
                if(mp1[i] != 0) a++;
                if(mp2[i] != 0) b++;
            }

            if(a == b) cnt++;
        }

        return cnt;
    }
};