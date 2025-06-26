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

        // int zeros = 0;
        // for(char ch : s){
        //     if(ch == '0') zeros++;
        // }
        // int ans = zeros;
        // int maxi = zeros;
        int maxi = 0;
        // int ones = 0;
        // int zeros = 0;

        string str = "";
        int strLen = 0;
        int i;
        for(i = n-1 ; i >= 0 ; i--){
            if(s[i] == '0'){ 
                str = '0' + str;
                strLen++;
            }
            else{
                // ones++;
                str = '1' + str;
                if(check(str, k) == true){
                    strLen++;
                }
            }
        }

        maxi = max(maxi, strLen);

        int cntZero = 0;
        while(i >= 0){
            if(s[i] == '0') cntZero++;
        }

        return maxi + cntZero;
    }
};
// 633,480,354