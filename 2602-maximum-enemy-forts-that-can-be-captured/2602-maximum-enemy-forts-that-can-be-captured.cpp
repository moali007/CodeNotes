class Solution {
public:
    int captureForts(vector<int>& forts) {
        int n = forts.size();
        
        int prev = 0, zero = 0, maxCnt = 0;

        for(int i=0;i<n;i++){
            if(forts[i] != 0){
                if(forts[i] == -forts[prev]){
                    maxCnt = max(maxCnt, zero);
                    zero = 0;
                    prev = i;
                }else{
                    zero = 0;
                    prev = i;
                }

            }else{
                zero++;
            }
        }

        return maxCnt;

    }
};