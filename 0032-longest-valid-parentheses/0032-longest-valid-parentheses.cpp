class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        if(n == 0) return 0;

        stack<int> st;
        st.push(-1);

        int maxlen = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    maxlen = max(maxlen, i - st.top());
                }
            }
        }

        return maxlen;
    }
};