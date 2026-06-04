class Solution {
public:
    int solve(string s){
        int n = s.length();
        if(n < 3) return 0;

        int cnt = 0;
        for(int i = 1; i < n-1; i++){
            if(s[i] - '0' > s[i-1] - '0' and s[i] - '0' > s[i+1] - '0'){
                cnt++;
            }
            else if(s[i] - '0' < s[i-1] - '0' and s[i] - '0' < s[i+1] - '0'){
                cnt++;
            }
        }

        return cnt;
    }

    int totalWaviness(int num1, int num2) {
        int ans = 0;

        for(int num = num1; num <= num2; num++){
            ans += solve(to_string(num));
        }

        return ans;
    }
};