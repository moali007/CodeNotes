class Solution {
public:

    int mod = 1e9 + 7;

    int numSub(string s) {
        int n = s.length();
        int i=0,j=0;
        long cnt=0;

        while(j < n){

           if(s[j] == '0'){
                i=j+1;
           }

           cnt += (j-i+1)%mod;
           j++;
        }
        return cnt%mod;
    }
};