class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();

        int i=0, j = 0;
        int white = 0;
        int mini = INT_MAX;
        
        while(j < n){
            if(blocks[j] == 'W'){
                white++;
            }

            if(j - i + 1 == k){
                mini = min(mini, white);

                if(blocks[i] == 'W'){
                    white--;
                }
                i++;
            }

            j++;
        }

        return mini;
    }
};