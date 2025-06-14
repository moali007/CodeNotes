class Solution {
public:
    int minMaxDifference(int num) {
        
        string s = to_string(num);
        int n = s.length();

        unordered_map<char, vector<int>> mp; //{num -> {indexes}}
        for(int i=0;i<n;i++){
            mp[s[i]].push_back(i);
        }


        string maxStr = s;
        char firstNonNine;

        for(int i=0 ; i<n ; i++){
            if(s[i] != '9'){
                firstNonNine = s[i];
                break;
            }
        }

        vector<int> v = mp[firstNonNine];

        for(int idx : v){
            maxStr[idx] = '9';
        }

        
        vector<int> v1 = mp[s[0]];
        string minStr = s;

        for(int idx : v1){
            minStr[idx] = '0';
        }


        return stoi(maxStr) - stoi(minStr);

        
    }
};