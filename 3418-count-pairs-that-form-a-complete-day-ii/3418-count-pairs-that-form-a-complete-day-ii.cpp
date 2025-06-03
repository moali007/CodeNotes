class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        int n = hours.size();

        for(int i = 0; i < n; i++){
            hours[i] = hours[i] % 24;
        }

        long long count = 0;
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++){
            count += mp[(24 - hours[i]) % 24];

            mp[hours[i]]++;
        }

        return count;
    }
};