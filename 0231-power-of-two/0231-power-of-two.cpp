class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == INT_MIN) return false;
        int setBits = __builtin_popcount(n);

        return setBits == 1;
    }
};