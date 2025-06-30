class Solution {
public:
    bool isValid(string s) {
        int n = s.length();

        if(s[0] != 'a') return false;

        stack<char> st;

        for(int i = 0; i < n; i++){
            char ch = s[i];

            if(ch == 'a'){
                st.push(ch);
            }
            else if(ch == 'b'){
                if(!st.empty() && st.top() == 'a'){
                    st.push(ch);
                }else{
                    return false;
                }
            }
            else{
                //ch == 'c'
                if(!st.empty() && st.top() == 'b'){
                    st.pop();
                    if(!st.empty() && st.top() == 'a'){
                        st.pop();
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }
        }

        return st.empty();
    }
};