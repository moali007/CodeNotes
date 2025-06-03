class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.length();

        int cnt = 1;
        int maxi = 0;

        for(int i=1;i<n;i++){
            if(s[i] == s[i-1] + 1){
                cnt++;
                maxi = max(maxi, cnt);
            }
            else{
                cnt = 1;
            }
        }
        
        return maxi == 0 ? 1 : maxi;
    }
};