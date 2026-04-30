class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.length();

        char prev = s[0];
        int len = 1;
        int maxi = 0;

        for(int i = 1; i < n; i++){
            if(s[i] == prev + 1){
                len++;
                maxi = max(maxi, len);
            }else{
                len = 1;
            }
            prev = s[i];
        }

        return maxi == 0 ? 1 : maxi;
    }
};
