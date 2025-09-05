class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int cnt = 0;

        if(num1 < num2) return -1;

        for(long long i = 0; i <= 60; i++){
            long long diff = 1LL*num1 - (1LL*num2)*i;
            long long bits = __builtin_popcountll(diff);
            if(bits <= i and i <= diff) return i;
        }
        return -1;
    }
};