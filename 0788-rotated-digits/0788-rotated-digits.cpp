class Solution {
public:
    
    bool isNotSame(int n){
        bool diff = false;
        int num = n;

        while(num > 0){
            int d = num % 10;
            num = num / 10;

            if(d == 3 || d == 4 || d == 7){
                return false;
            }
            if(d == 2 || d == 5 || d == 6 || d == 9){
                diff = true;
            }
        }

        return (diff == true);
    }

    int rotatedDigits(int n) {
        int cnt = 0;
        for(int i = 0; i <= n; i++){
            if(isNotSame(i)) cnt++;
        }

        return cnt;
    }
};