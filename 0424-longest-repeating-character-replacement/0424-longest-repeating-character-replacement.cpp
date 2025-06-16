class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();

        vector<int> hash(26, 0);
        int i=0,j=0;
        int maxfreq = 0;
        int maxlen = 0;

        while(j < n){
            hash[s[j] - 'A']++;
            maxfreq = max(maxfreq, hash[s[j] - 'A']);

            if((j-i+1) - maxfreq > k){
                hash[s[i] - 'A']--;
                for(int i = 0; i < 26; i++){
                    maxfreq = max(maxfreq, hash[i]);
                }
                i++;
            }

            if((j-i+1) - maxfreq <= k){
                maxlen = max(maxlen, j-i+1);
            }

            j++;
        }

        return maxlen;
    }
};