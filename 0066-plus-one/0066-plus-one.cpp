class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        int i = n-1;

        if(digits[i] != 9){
            digits[i] += 1;
        }else{
            while(i >= 0 && digits[i] == 9){
                digits[i] = 0;
                i--;
            }
            if(i >= 0){
                digits[i] += 1;
            }else{
                digits.insert(digits.begin(), 1);
            }
        }

        return digits;
    }
};