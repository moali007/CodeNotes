class Solution {
public:
    
    bool isPrime(int num){
        if(num < 2) return false;
         
        for(long long i=2;i*i<=num;i++){
            if(num % i == 0) return false;
        }
        return true;
     }

    int countPrimeSetBits(int left, int right) {
        int cnt = 0;

        for(int n = left; n <= right; n++){
            int set_bits = __builtin_popcount(n);

            if(isPrime(set_bits)) cnt++;
        }

        return cnt;
    }
};
//int num
//int set_bits = __builtin_popcount(num)
//isPrime(set_bits) -> count++