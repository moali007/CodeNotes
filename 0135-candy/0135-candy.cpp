class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> candy(n, 1);

        //checking L to R previous
        for(int i=1;i<n;i++){
            if(ratings[i] > ratings[i-1]){
                candy[i] = candy[i-1] + 1;
            }
        }

        //checking R to L next
        for(int i=n-2;i>=0;i--){
            if(ratings[i] > ratings[i+1]){
                if(candy[i] <= candy[i+1]){
                    candy[i] = candy[i+1] + 1;
                }
            }
        }

        int totalCandy = accumulate(candy.begin(), candy.end(), 0);

        return totalCandy;
    }
};