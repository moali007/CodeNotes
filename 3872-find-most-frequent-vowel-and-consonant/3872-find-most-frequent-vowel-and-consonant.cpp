class Solution {
public:
    int maxFreqSum(string s) {
        int n = s.length();

        vector<int> freq(26, 0);

        for(char ch : s){
            freq[ch - 'a']++;
        }

        int maxConsonant = 0;
        int maxVowel = 0;

        for(int i = 0; i < 26; i++){
            char ch = i + 'a';
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                maxVowel = max(maxVowel, freq[i]);
            }
            else maxConsonant = max(maxConsonant, freq[i]);
        }

        return maxConsonant + maxVowel;
    }
};