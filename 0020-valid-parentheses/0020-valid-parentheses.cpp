class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;

        for(char ch : s){
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else{
                if(!st.empty()){
                    if(st.top() == '(' && ch == ')') st.pop();
                    else if(st.top() == '{' && ch == '}') st.pop();
                    else if(st.top() == '[' && ch == ']') st.pop();
                    else return false;

                }else{
                    return false;
                }
            }
        }

        return st.empty();
    }
};