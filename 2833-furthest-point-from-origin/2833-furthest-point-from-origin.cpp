class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int R = 0;
        int L = 0;
        int dash = 0;

        for(char ch : moves){
            if(ch == 'R') R++;
            else if(ch == 'L') L++;
            else dash++;
        }

        return abs(R-L) + dash;
    }
};