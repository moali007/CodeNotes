class Solution {
public:
    int maxDifference(string s) {
        int n = s.length();

        unordered_map<char, int> mp;
        for(char ch : s){
            mp[ch]++;
        }

        int maxOddFreq = INT_MIN;
        int minEvenFreq = INT_MAX;

        for(auto it : mp){
            if(it.second % 2 != 0){
                maxOddFreq = max(maxOddFreq, it.second);
            }
            else minEvenFreq = min(minEvenFreq, it.second);
        }

        return maxOddFreq - minEvenFreq;
    }
};