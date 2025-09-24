class Solution {
public:
    
    int maxConsecutiveTrue(string str, int k){
        int n = str.length();

        int falseCnt = 0;
        int maxi = 0;
        int i = 0, j = 0;

        while(j < n){
            if(str[j] == 'F') falseCnt++;

            while(falseCnt > k){
                if(str[i] == 'F') falseCnt--;
                i++;
            }

            maxi = max(maxi, j - i + 1);
            j++;
        }

        return maxi;
    }

    int maxConsecutiveFalse(string str, int k){
        int n = str.length();

        int trueCnt = 0;
        int maxi = 0;
        int i = 0, j = 0;

        while(j < n){
            if(str[j] == 'T') trueCnt++;

            while(trueCnt > k){
                if(str[i] == 'T') trueCnt--;
                i++;
            }

            maxi = max(maxi, j - i + 1);
            j++;
        }

        return maxi;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans1 = maxConsecutiveTrue(answerKey, k);
        int ans2 = maxConsecutiveFalse(answerKey, k);

        return max(ans1, ans2);
    }
};