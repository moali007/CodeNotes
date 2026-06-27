class Solution {
public:
    int maximumLength(vector<int>& nums) {
        
        map<long long, int> mp;

        for(int num : nums) mp[num]++;

        int ans = 1;

        for (auto [start, freq] : mp) {
            long long x = start;
            int len = 0;

            while (mp.count(x)) {
                if (x == 1) {
                    len += mp[1];
                    break;
                }

                if (mp[x] >= 2)
                    len += 2;
                else {
                    len++;
                    break;
                }

                x *= x;
            }

            if (len % 2 == 0) len--;
            ans = max(ans, len);
        }

        return ans;
    }
};