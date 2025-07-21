class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();

        string result = "";
        result.push_back(s[0]);

        for(int i = 1; i < n; i++){
            if(i+1 < n && s[i] == s[i-1] && s[i] == s[i+1]){
                continue;
            }

            result.push_back(s[i]);
        }

        return result;
    }
};