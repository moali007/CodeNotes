class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.rbegin(), cost.rend());

        int i = 0;
        int c = 0;
        while(i < n){
            c += cost[i];
            if(i+1 < n) c += cost[i+1];

            i += 3;
        }

        return c;
    }
};