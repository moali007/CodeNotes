class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();

        vector<int> freq(26, 0);
        int i = 0, j = 0;
        int maxfreq = 0, maxlen = 0;

        while(j < n){
            freq[s[j] - 'A']++;
            maxfreq = max(maxfreq, freq[s[j] - 'A']);

            while((j-i+1 - maxfreq) > k){
                freq[s[i] - 'A']--;
                i++;
            }

            maxlen = max(maxlen, j-i+1);
            j++;
        }

        return maxlen;
    }
};