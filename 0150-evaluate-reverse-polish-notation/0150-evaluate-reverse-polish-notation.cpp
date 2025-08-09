class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        unordered_map<string, char> mp;
        mp["*"] = '*';
        mp["+"] = '+';
        mp["-"] = '-';
        mp["/"] = '/';

        for(auto it : tokens){
            if(it == "+" || it == "-" || it == "*" || it == "/"){
                int num2 = stoi(st.top()); st.pop(); 
                int num1 = stoi(st.top()); st.pop(); 

                // int num3 = num1 (mp[it]-'0') num2;
                if(it == "+") st.push(to_string(num1 + num2));
                else if(it == "-") st.push(to_string(num1 - num2));
                else if(it == "*") st.push(to_string(num1 * num2));
                else if(it == "/") st.push(to_string(num1 / num2));
            }else{
                st.push(it);
            }
        }

        return stoi(st.top());
    }
};