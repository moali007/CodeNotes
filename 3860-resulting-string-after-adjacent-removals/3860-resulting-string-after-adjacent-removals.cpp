class Solution {
public:

    bool isAdjacent(char ch1, char ch2){
        //checks if ch2 is adjacent char of ch1
        int idx = ch1 - 'a';

        int next_idx = (idx + 1) % 26;
        char next_char = 'a' + next_idx;

        int prev_idx = (idx - 1 + 26) % 26;
        char prev_char = 'a' + prev_idx;

        return (ch2 == next_char || ch2 == prev_char);
    }

    string resultingString(string s) {

        int n = s.length();
        stack<char> st;
        st.push(s[0]);

        for(int i=1;i<n;i++){
           char ch1 = s[i];

            if(!st.empty()){
                    char ch2 = st.top();
                    if(isAdjacent(ch2, ch1) == true){
                        st.pop();
                    }else{
                        st.push(ch1);
                    }
            }
            else{
                    st.push(ch1);
            }
        }

        if(st.empty()) return "";
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};