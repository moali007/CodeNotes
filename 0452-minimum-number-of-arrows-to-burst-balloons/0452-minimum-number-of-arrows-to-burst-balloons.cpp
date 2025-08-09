class Solution { 
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto& it : points) {
            pq.push({it[1], it[0]});  
        }

        int cnt = 0;
        int prev = -1;

        while (!pq.empty()) {
            auto [num2, num1] = pq.top();
            pq.pop();

            if (prev == -1 || num1 > prev) {
                cnt++;
                prev = num2; 
            }
        }

        return cnt;
    }
};
