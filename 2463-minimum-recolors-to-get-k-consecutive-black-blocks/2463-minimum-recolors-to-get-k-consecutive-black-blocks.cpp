class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();

        int i=0, j = k-1;
        int white = 0;
        int mini = INT_MAX;
        for(int it = i; it <= j; it++){
            if(blocks[it] == 'W'){
                white++;
            }
        }

        mini = min(mini, white);
        i++;
        j++;

        while(j < n){
            white = 0;

            for(int it = i; it <= j; it++){
                if(blocks[it] == 'W'){
                    white++;
                }
            }


            mini = min(mini, white);

            i++;
            j++;
        }

        return mini;
    }
};