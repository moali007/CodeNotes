class Solution {
public:
    
    int solve(int childCount, int n, int limit){
        if(childCount == 3){
            if(n == 0) return 1;

            return 0;
        }
        // if((childCount == 3 && n != 0) || (n == 0 && childCount != 3)) return 0;

        int ways = 0;
        for(int assign=0;assign<=limit;assign++){

            ways += solve(childCount + 1, n - assign, limit);
        }

        return ways;
    }

    int distributeCandies(int n, int limit) {
        
        return solve(0, n, limit);
    }
};