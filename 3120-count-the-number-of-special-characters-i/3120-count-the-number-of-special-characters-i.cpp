class Solution {
public:
    int numberOfSpecialChars(string word) {
        sort(word.begin(), word.end());
        cout<<word<<endl;
        unordered_map<char, int> mp;
        int cnt = 0;

        for(char ch : word){
            if(mp.count(ch - 32)){
                mp.erase(ch-32);
                cnt++;
            }

            mp[ch]++;
        }

        return cnt;
    }
};
