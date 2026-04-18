class Solution {
public:
    int mirrorDistance(int n) {
        int rev = 0;
        int m = n;

        while(m > 0){
            int d = m % 10;
            m = m / 10;
            rev = rev * 10 + d;
        }

        return abs(n - rev);
        
    }
};