class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();

        int i = 0, j = 0;
        vector<int> hash(26, 0);
        int maxfreq = 0, maxlen = 0;

        while(j < n){
            hash[s[j] - 'A']++;
            maxfreq = max(maxfreq, hash[s[j] - 'A']);

            while((j-i+1 - maxfreq) > k){
                hash[s[i] - 'A']--;
                i++;
            }

            maxlen = max(maxlen, j-i+1);
            j++;
        }

        return maxlen;
    }
};