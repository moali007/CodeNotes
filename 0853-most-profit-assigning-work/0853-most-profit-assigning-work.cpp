class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=profit.size(), m=worker.size();

        vector<pair<int,int>> temp(n);

        for(int i=0; i<n; i++){
            temp[i]={difficulty[i], profit[i]};
        }

        sort(temp.begin(), temp.end());
        sort(worker.begin(), worker.end());
        
        int maxProfit=0,  idx=0, bestProfit = 0;

        for (int i = 0; i < m; i++) {
            // Increase index to the next worker's ability
            while (idx < n && worker[i] >= temp[idx].first) {
                bestProfit = max(bestProfit, temp[idx].second);
                idx++;
            }
            maxProfit+= bestProfit;
        }
        return maxProfit;
        
        
        
    }
};