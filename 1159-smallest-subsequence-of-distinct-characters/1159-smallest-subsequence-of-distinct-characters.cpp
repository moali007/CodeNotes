class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();

        vector<bool> taken(26, false);
        vector<int> lastIdx(26);

        for(int i=0;i<n;i++){
            lastIdx[s[i] - 'a'] = i;
        }

        stack<char> st;

        for(int i=0;i<n;i++){
            char ch = s[i];
            int idx = ch - 'a';

            if(taken[idx] == true) continue;

            while(!st.empty() && st.top() > ch && lastIdx[st.top() - 'a'] > i){
                taken[st.top() - 'a'] = false;
                st.pop();
            }

            taken[idx] = true;
            st.push(ch);
        }

        string result = "";
        while(!st.empty()){
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};