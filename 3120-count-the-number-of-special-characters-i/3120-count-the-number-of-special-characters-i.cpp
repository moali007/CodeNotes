class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> freq(52, 0);

        for(char ch : word){
            if(islower(ch)){
                freq[ch - 'a']++;
            }else{
                freq[ch - 'A' + 26]++;
            }
        }

        int cnt = 0;
        for(int i = 0; i < 26; i++){
            if(freq[i] > 0 and freq[i+26] > 0) cnt++;
        }

        return cnt;
    }
};