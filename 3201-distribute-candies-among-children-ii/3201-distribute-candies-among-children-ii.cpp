class Solution {
public:
    long long distributeCandies(int n, int limit) {
        
        long long ways = 0;

        // finding min and max assignment for child1

        int minCh1 = max(0, n - 2*limit);  //assigning child2 & child3 limit candies, 
        //agar limi > n hua to n-limit will be -ve, to avoid tak max(0, 2*limit)
        int maxCh1 = min(n, limit);
        //agar limit>n hua to gadbad hoga isi live take min(n, limit);

        for(int i = minCh1 ; i <= maxCh1 ; i++){
            // i candies child1 ko assign kardi
            //remaining
            int N = n - i;
            // 2 children case
            //agar mininum kitni candy de sakte hai child2 ko nikalna hai to child3 ko limit candies dedo
            //then n - limit, itni min candy ch2 ko milegi
            int minCh2 = max(0, N - limit); 
            int maxCh2 = min(N, limit);

            ways += maxCh2 - minCh2 + 1;
        }

        return ways;
    }
};