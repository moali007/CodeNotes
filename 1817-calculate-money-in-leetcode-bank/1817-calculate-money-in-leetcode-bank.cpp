class Solution {
public:
    int totalMoney(int n) {
        int st = 1;
        int sum = 0;

        int week = n / 7;
        int rem = n % 7;

        while(week > 0){
            int curr = st;
            for(int i = 0; i < 7; i++){
                sum += curr;
                curr++;
            }
            st++;
            week--;
        }
        
        int curr = st;
        for(int i = 0; i < rem; i++){
            sum += curr;
            curr++;
        }

        return sum;
    }
};