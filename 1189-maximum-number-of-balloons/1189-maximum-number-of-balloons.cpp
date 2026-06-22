class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mp;

        for(char ch : text){
            mp[ch]++;
        }

        string s = "balloon";

        int cnt = INT_MAX;

        for(char ch : s){
            if(mp.find(ch) == mp.end()){
                return 0;
            }

            if(ch == 'b' || ch == 'a' || ch == 'n'){
                cnt = min(cnt, mp[ch]);
            }
            else if(ch == 'l' || ch == 'o'){
                cnt = min(cnt, mp[ch] / 2);
            }
        }

        return cnt;
    }
};

