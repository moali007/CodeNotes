class Solution {
public:
    bool canPlaceFlowers(vector<int>& flower, int n) {
        int m = flower.size();

        for(int i = 0; i < m; i++){
            if(flower[i] == 0)
            {
                if((i == 0 || flower[i-1] == 0) && (i == m-1 || flower[i+1] == 0)){
                    flower[i] = 1;
                    n -= 1;
                }
            
            }
        }

        return n <= 0;
    }
};