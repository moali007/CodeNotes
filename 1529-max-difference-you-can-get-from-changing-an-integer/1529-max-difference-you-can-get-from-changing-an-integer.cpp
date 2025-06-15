class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        int n = s.length();

        unordered_map<char, vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[s[i]].push_back(i);
        }

        //make a 
        //find first non 9 & convert all occurance of it to 9
        string a = s;
        char firstNonNine;
        for(int i=0;i<n;i++){
            if(s[i] != '9'){
                firstNonNine = s[i];
                break;
            }
        }

        vector<int> v = mp[firstNonNine];
        for(int idx : v){
            a[idx] = '9';
        }

        //make b
        //find first char of s & convert all ocuurances of it to 1
        string b = s;
        char first = s[0];
        if(first != '1'){
            vector<int> v1 = mp[first];

            for(int idx : v1){
                b[idx] = '1';
            }
        }
        else{
            //first is one 
            //find first non 1
            char firstNonOne;
            for(int i=0;i<n;i++){
                if(s[i] != '1' && s[i] != '0'){
                    firstNonOne = s[i];
                    break;
                }
            }

            vector<int> notOne = mp[firstNonOne];
            for(int idx : notOne){
                b[idx] = '0';
            }
        }

        return stoi(a) - stoi(b);


    }
};