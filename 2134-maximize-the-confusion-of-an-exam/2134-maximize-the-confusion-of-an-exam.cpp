class Solution {
public:
    int n;

    int maxTrueWithKfalse(string &s, int k){
        int i=0,j=0;
        int falseCnt = 0;
        int maxlen = 0;

        while(j < n){
            if(s[j] == 'F'){
                falseCnt++;
            }

            while(falseCnt > k){
                if(s[i] == 'F'){
                    falseCnt--;
                }
                i++;
            }

            maxlen = max(maxlen, j-i+1);

            j++;
        }

        return maxlen;
    }

    int maxFalseWithKtrue(string &s, int k){
        int i=0,j=0;
        int trueCnt = 0;
        int maxlen = 0;

        while(j < n){
            if(s[j] == 'T'){
                trueCnt++;
            }

            while(trueCnt > k){
                if(s[i] == 'T'){
                    trueCnt--;
                }
                i++;
            }

            maxlen = max(maxlen, j-i+1);

            j++;
        }

        return maxlen;
    }
    
    int maxConsecutiveAnswers(string answerKey, int k) {
        n = answerKey.length();
        
        int maxConsequetiveTrue = maxTrueWithKfalse(answerKey, k);
        int maxConsequetiveFalse = maxFalseWithKtrue(answerKey, k);


        return max(maxConsequetiveTrue, maxConsequetiveFalse);
    }
};