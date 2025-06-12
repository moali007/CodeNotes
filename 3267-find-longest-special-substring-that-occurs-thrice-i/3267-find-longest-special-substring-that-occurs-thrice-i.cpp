class Solution {
public:

    int maximumLength(string s) {
        int n = s.length();

        map<pair<char, int>, int> mp;
        for(int i=0;i<n;i++){
            char ch = s[i];
            int l=0;
            for(int j=i;j<n;j++){
                if(s[j] == ch){
                    l++;
                    mp[{ch, l}]++;
                }else{
                    break;
                }
            }
        }

        int maxlen = -1;
        for(auto it : mp){
            int curr_str_length = it.first.second;
            int freq = it.second;

            if(freq >= 3){
                maxlen = max(maxlen, curr_str_length);
            }
        }

        return maxlen;
    }
};