class Solution {
public:
    int hammingDistance(int x, int y) {
        int num = x ^ y;
        // int c = __builtin_popcount(num); //counts no. of set bits
        int c = 0;
        while(num > 1){
            c += num&1;

            num = num >> 1;
        }
        if(num == 1) c += 1;

        return c;
    }
};