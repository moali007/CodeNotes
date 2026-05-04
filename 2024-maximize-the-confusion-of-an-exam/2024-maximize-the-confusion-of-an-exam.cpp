class Solution {
public:
    int f1(string &s, int k){
        int n = s.length();

        int i = 0, j = 0;
        int tc = 0;
        int maxi = 0;

        while(j < n){
            if(s[j] == 'T') tc++;

            while(tc > k){
                if(s[i] == 'T') tc--;
                i++;
            }

            maxi = max(maxi, j-i+1);
            j++;
        }

        return maxi;
    }

    int f2(string &s, int k){
        int n = s.length();

        int i = 0, j = 0;
        int fc = 0;
        int maxi = 0;

        while(j < n){
            if(s[j] == 'F') fc++;

            while(fc > k){
                if(s[i] == 'F') fc--;
                i++;
            }

            maxi = max(maxi, j-i+1);
            j++;
        }

        return maxi;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        //f1 - flip k  'T'
        //f2 - flip k 'F'
        //return max(f1, f2)
        return max(f1(answerKey, k), f2(answerKey, k));
    }
};


