class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.length();

        vector<string> result;
        int i = 0;

        while(i + k < n){
            string str = s.substr(i, k);
            result.push_back(str);

            i = i + k;
        }

        string rem = s.substr(i, n - i);
        while(rem.length() < k){
            rem += fill;
        }

        result.push_back(rem);

        return result;
    }
};