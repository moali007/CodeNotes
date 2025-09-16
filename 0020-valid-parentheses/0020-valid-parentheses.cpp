class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;

        for(char ch : s){
            if(ch == '(' || ch == '[' || ch == '{'){
                st.push(ch);
            }
            else if(!st.empty() and ch == ')' && st.top() == '('){
                st.pop();
            }
            else if(!st.empty() and ch == ']' && st.top() == '['){
                st.pop();
            }
            else if(!st.empty() and ch == '}' && st.top() == '{'){
                st.pop();
            }
            else return false;
        }

        return st.empty();
    }
};