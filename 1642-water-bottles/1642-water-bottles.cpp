class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
       int ans = numBottles;

       while(numBottles >= numExchange){
          int d = numBottles / numExchange;
          int r = numBottles % numExchange;

          ans += d;

          numBottles = d + r;
       }

       return ans;
    }
};