class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();

        for(int i=0;i<n;i++){
            time[i] = time[i] % 60;
        }

        //Now this question becomes similar to two sum with target = 60
        
        unordered_map<int, int> mp;

        int cnt = 0;

        for(int i=0;i<n;i++){
                int rem = (60 - time[i]) % 60;
                cnt += mp[rem];

            mp[time[i]]++;
        }

        return cnt; 
    }
};