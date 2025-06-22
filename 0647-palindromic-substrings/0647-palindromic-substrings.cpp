class Solution {
public:
    
    bool isPallindrome(string str, int i, int j){
        // int i=0;
        // int j=str.length()-1;

        while(i < j){
            if(str[i] != str[j]) return false;
            else{
                i++,j--;
            }
        }

        return true;
    }

    int countSubstrings(string s) {
        int n = s.length();

        int cnt = 0;
        for(int i = 0; i<n;i++){
            for(int j=i;j<n;j++){
                int len = j-i+1;
                if(isPallindrome(s, i, i + len - 1)) cnt++;
            }
        }

        return cnt;
    }
};