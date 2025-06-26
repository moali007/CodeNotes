class Solution {
public:
    
    bool check(string str, int k){
        long long val = 0;
        int p = 0;
        for(int i = str.length() - 1 ; i >= 0 ; i--){
            val += (str[i] - '0') * pow(2, p);
            p++;
            if(p >= 32) return false;
        }

        return val <= k;
    }

    int longestSubsequence(string s, int k) {
        int n = s.length();

        int zeros = 0;
        for(char ch : s){
            if(ch == '0') zeros++;
        }

        int maxi = zeros;
        int ones = 0;

        string str = "";
        for(int i = n-1 ; i >= 0 ; i--){
            if(s[i] == '0') str = '0' + str;
            else{
                ones++;
                str = '1' + str;
                if(check(str, k) == true){
                    maxi = max(maxi, zeros+ones);
                }
            }
        }

        return maxi;
    }
};