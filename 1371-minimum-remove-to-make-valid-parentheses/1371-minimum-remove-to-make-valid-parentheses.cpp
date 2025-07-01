class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();

        stack<int> st;
        unordered_set<int> deleteIdx;

        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                if(!st.empty()){
                    st.pop();
                }else{
                    deleteIdx.insert(i);
                }
            }
        }

        while(!st.empty()){
            deleteIdx.insert(st.top());
            st.pop();
        }

        string result = "";
        for(int i = 0; i < n; i++){
            if(deleteIdx.count(i)) continue;

            result += s[i];
        }

        return result;
    }
};