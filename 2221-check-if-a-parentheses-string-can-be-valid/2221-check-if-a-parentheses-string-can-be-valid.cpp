class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if(n % 2 != 0) return false;

        stack<int> open; //stores index of open parenthesis when locked[i] = 1
        stack<int> openClose; //stores of indexes of parethesis when locked[i] = 0

        for(int i = 0; i < n; i++){
            if(s[i] == '(' && locked[i] == '1'){
                open.push(i);
            }
            else if((s[i] == '(' || s[i] == ')') && locked[i] == '0'){
                openClose.push(i);
            }
            else if(s[i] == ')' && locked[i] == '1'){
                //first check in open stack
                if(!open.empty()){
                    open.pop();
                }
                else if(!openClose.empty()){//then check in openClose stack
                    openClose.pop();
                }
                else return false;
            }
        }

        while(!open.empty() && !openClose.empty() && open.top() < openClose.top()){
            open.pop();
            openClose.pop();
        }

        return open.empty();
    }
};