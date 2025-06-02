class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.rbegin(), cost.rend());

        int total = accumulate(cost.begin(), cost.end(), 0);

        if(n < 3) return total;

        int i = 2;
        while(i < n){
            total -= cost[i];
            i += 3; 
        }

        return total;

    }
};