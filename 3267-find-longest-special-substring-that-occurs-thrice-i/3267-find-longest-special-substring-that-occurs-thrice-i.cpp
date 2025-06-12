class Solution {
public:
    
    bool isSpecial(string s){
        unordered_map<char, int> mp;
        for(char ch : s){
            mp[ch]++;
        }

        return mp.size() == 1;
    }

    int maximumLength(string s) {
        int n = s.length();

        unordered_map<string, int> mp; //keeps count of all special substrings

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                string sub = s.substr(i, j-i+1);

                if(isSpecial(sub)){
                    mp[sub]++;
                }
            }
        }

        int maxlen = -1;
        for(auto it : mp){
            if(it.second >= 3){
                string str = it.first;
                int len = str.length();
                maxlen = max(maxlen, len);
            }
        }

        return maxlen;
    }
};