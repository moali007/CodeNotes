class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        if(t.length() > n) return "";

        unordered_map<char, int> mp;
        for(char ch : t){
            mp[ch]++;
        }

        int i = 0, j = 0;
        int requiredCnt = t.length();
        int minwindow = INT_MAX;
        int start_i = -1;



        while(j < n){
            if(mp[s[j]] > 0){
                requiredCnt--;
            }

            mp[s[j]]--;

            while(requiredCnt == 0){
                //shrink
                int currentWindow = j-i+1;
                if(currentWindow < minwindow){
                    minwindow = currentWindow;
                    start_i = i;
                }

                mp[s[i]]++;

                if(mp[s[i]] > 0){
                    requiredCnt++;
                }
                i++;
            }

            j++;
        }

        return start_i == -1 ? "" : s.substr(start_i, minwindow);
    }
};