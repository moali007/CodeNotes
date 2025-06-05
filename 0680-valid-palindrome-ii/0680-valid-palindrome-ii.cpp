class Solution {
public:
    
    bool isPallindrome(string &s, int i, int j){
        
        while(i <= j){
            if(s[i] != s[j]){
                return false;
            }else{
                i++,j--;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int n = s.length();

        int i = 0;
        int j = n-1;

        while(i <= j){
            if(s[i] != s[j]){
                //ek baar s[i] remove karke dekh lo
                //ek barr s[j] remove karke dekh lo

                return isPallindrome(s, i+1, j) || isPallindrome(s, i, j-1);

            }else{
                i++,j--;
            }
        }

        return true;
    }
};