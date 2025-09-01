class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double,int>> pq; //max heap
        
        for(int i=0;i<n;i++){
            double curr_PR = (double) classes[i][0]/classes[i][1];
            double new_PR = (double) (classes[i][0] + 1)/(classes[i][1] + 1);
            double delta = new_PR - curr_PR;
            pq.push({delta,i});
        }

        while(extraStudents--){
            auto curr = pq.top();
            pq.pop();

            int max_delta = curr.first;
            int idx = curr.second;

            classes[idx][0]++; //increment total passing students at index=idx
            classes[idx][1]++; //increment total students at index=idx

            double curr_PR = (double) classes[idx][0]/classes[idx][1];
            double new_PR = (double) (classes[idx][0] + 1)/(classes[idx][1] + 1);
            double delta = new_PR - curr_PR;
            pq.push({delta,idx});
        }

        double PR_sum = 0.0;
        for(int i=0;i<n;i++){
            PR_sum += (double) classes[i][0]/classes[i][1];
        }

        return PR_sum/n;
    }
};