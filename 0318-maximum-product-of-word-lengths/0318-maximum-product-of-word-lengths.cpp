class Solution {
public:
    bool notPresent(string &s, string &t){
        vector<int> freq(26, 0);
        for(char ch : s){
            freq[ch - 'a'] = 1;
        }

        for(char ch : t){
            if(freq[ch - 'a'] == 1) return false;
        }

        return true;
    }

    int maxProduct(vector<string>& words) {
        int n = words.size();
        
        int maxi = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){

                if(notPresent(words[i], words[j])){
                    int len = words[i].length() * words[j].length();
                    maxi = max(maxi, len);
                }
            }
        }

        return maxi;
    }
};