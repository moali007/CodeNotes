class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.length();

        int north = 0;
        int south = 0;
        int east = 0;
        int west = 0;
        int maxMD = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == 'N') north++;
            else if(s[i] == 'S') south++;
            else if(s[i] == 'E') east++;
            else west++;

            int currMD = abs(east-west) + abs(north-south);
            int steps = i+1;

            int wasted = steps - currMD;
            
            int extra = 0;
            if(wasted != 0){
                extra = min(2*k, wasted);
            }

            int finalCurrMD = currMD + extra;
            maxMD = max(maxMD, finalCurrMD);
        }

        return maxMD;
    }
};