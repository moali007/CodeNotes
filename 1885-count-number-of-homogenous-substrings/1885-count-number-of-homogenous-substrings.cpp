class Solution {
public:
    int mod = 1e9 + 7;
    int countHomogenous(string s) {
        const int inv2 = 500000004;
        s += '*';  // Add sentinel to flush last group
        int n = s.length();
        int cnt = 1;
        long long ans = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                cnt++;
            } else {
                long long temp = ((long long)cnt * (cnt + 1)) % mod;
                temp = (temp * inv2) % mod;  // Division by 2 under modulo
                ans = (ans + temp) % mod;
                cnt = 1;
            }
        }
        return ans % mod;
    }
};
