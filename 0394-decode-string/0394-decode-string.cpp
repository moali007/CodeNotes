class Solution {
public:
    string decodeString(string s) {
        
        stack<int> digit;
        stack<string> st;
        int num = 0;

        for(char ch : s){
            if(isdigit(ch)){
                num = (num * 10) + (ch - '0');
            }
            else if(ch == '[' || isalpha(ch)){
                if(num > 0){
                    digit.push(num);
                    num = 0;
                }
                st.push(string(1, ch));               
            }
            else{
                string str = "";
                while(st.top() != "["){
                    str = st.top() + str;
                    st.pop();
                }
                st.pop();

                int freq = digit.top(); digit.pop();
                string res = str;
                while(freq > 1){
                    res = res + str;
                    freq--;
                }

                st.push(res);
            }
        }

        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};