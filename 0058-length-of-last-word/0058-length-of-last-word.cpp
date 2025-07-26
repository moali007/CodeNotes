class Solution {
public:
    int lengthOfLastWord(string str) {
        int cnt = 0;
        string s = " " + str + " ";
        while(s.back() == ' '){
            s.pop_back();
        }

        while(s.back() != ' '){
            s.pop_back();
            cnt++;
        }

        return cnt;
    }
};