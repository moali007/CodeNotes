class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long cost = 0;
        if(n<k && m<k) return 0;
        
        if(n > k){
            int log1 = n-k;
            int log2 = k;
            
            cost = (long long)log1 * log2;
            
        }
        else if(m > k){
            int log1 = m-k;
            int log2 = k;
            
            cost = (long long)log1 * log2;
        }
        // cout<<"Cost = "<<cost<<endl;
        
        return cost;
    }
};