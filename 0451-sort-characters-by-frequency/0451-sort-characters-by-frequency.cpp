class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();

        unordered_map<char, int> mp;
        for(char ch : s){
            mp[ch]++;
        }

        priority_queue<pair<int, char>> pq;
        for(auto it : mp){
            pq.push({it.second, it.first});
        }

        string ans = "";
        while(!pq.empty()){
            char ch = pq.top().second;
            int cnt = pq.top().first;
            pq.pop();

            ans += string(cnt, ch);
        }

        return ans;
    }
};