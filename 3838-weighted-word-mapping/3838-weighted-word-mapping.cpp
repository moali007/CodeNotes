class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res = "";

        for(string word : words){
            int wt = 0;
            
            for(char ch : word){
                wt += weights[ch - 'a'];
            }

            int mod = wt % 26;
            char ch = 25 - mod + 'a';
            res += ch;
        }

        return res;
    }
};

