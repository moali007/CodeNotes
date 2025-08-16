class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();

        unordered_map<char, int> mp; //{char, last_idx}
        for(int i = 0; i < n; i++){
            mp[s[i]] = i;
        }

        vector<int> result;
        int i=0, j=0;
        int last = mp[s[0]];

        while(j < n){

            if(j > last){
                result.push_back(j - i);
                i = j;
                last = mp[s[j]];
            }

            last = max(last, mp[s[j]]);
            j++;
        }

        result.push_back(j - i);

        return result;

        
    
    }
};