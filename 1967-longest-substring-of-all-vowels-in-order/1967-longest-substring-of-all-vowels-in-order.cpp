class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n = word.length();

        unordered_map<char, int> mp;
        mp[word[0]] = 1;
        int i=0;
        int j=1;
        int maxi = 0;

        while(j < n){

            if(word[j] >= word[j-1]){
                mp[word[j]]++;
            }
            else{
                mp.clear();
                i = j;
                mp[word[j]] = 1;
            }

            if(mp.size() == 5){
                maxi = max(maxi, j-i+1);
            }

            j++;
        }

        return maxi;
    }
};