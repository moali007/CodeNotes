class Solution {
public:
    bool checkZeroOnes(string s) {
        int n = s.length();

        int zero=0, maxConsecutiveZero = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '0'){
                zero++;
                maxConsecutiveZero = max(maxConsecutiveZero, zero);
            }
            else zero = 0;
        }

        int one=0, maxConsecutiveOne = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '1'){
                one++;
                maxConsecutiveOne = max(maxConsecutiveOne, one);
            }
            else one = 0;
        }

        return maxConsecutiveOne > maxConsecutiveZero;
    }
};