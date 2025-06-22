class Solution {
public:

    string longestPalindrome(string s) {
        int n = s.length();

        int count=0;
        int maxl = 0;
        int start = -1;
        int end = -1;

        for(int i=0;i<n;i++){
            //odd
            int l = i;
            int r = i;
            while(l>=0 && r<n && s[l]==s[r]){
                if(maxl < r - l + 1){
                    maxl = r - l + 1;
                    start = l;
                    end = r;
                }
                l--;
                r++;
            } 

            //even
            l = i;
            r = i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if(maxl < r - l + 1){
                    maxl = r - l + 1;
                    start = l;
                    end = r;
                }
                l--;
                r++;
            }

        }

        return s.substr(start, end-start+1);
    }
};