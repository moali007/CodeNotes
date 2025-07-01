class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();

        string str = "";
        //L to R : removing extra closing brackets
        int open = 0;
        for(int i = 0; i < n; i++){
            if(isalpha(s[i])){
                str += s[i];
            }
            else if(s[i] == '('){
                open++;
                str += s[i];
            }
            else if(s[i] == ')'){
                if(open > 0){
                    open--;
                    str += s[i];
                }else{
                    continue;
                }
            }
        }

        //R to L : removing extra open brackets from str
        string result = "";
        int close = 0;
        for(int i = str.length() - 1; i >= 0; i--){
            char ch = str[i];
            if(isalpha(ch)){
                result += ch;
            }
            else if(ch == ')'){
                close++;
                result += ch;
            }
            else if(ch == '('){
                if(close > 0){
                    close--;
                    result += ch;
                }else{
                    continue;
                }
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};