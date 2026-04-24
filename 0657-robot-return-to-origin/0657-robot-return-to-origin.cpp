class Solution {
public:
    bool judgeCircle(string moves) {
        int up = 0;
        int down = 0;
        int left = 0;
        int right = 0;

        for(char ch : moves){
            if(ch == 'U') up++;
            else if(ch == 'D') down++;
            else if(ch == 'L') left++;
            else right++;
        }

        if(up - down != 0 || left - right != 0) return false;
        return true;
    }
};