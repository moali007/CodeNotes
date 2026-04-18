class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();

        priority_queue<int> pq(piles.begin(), piles.end());

        while(k > 0){
            int num = pq.top();
            pq.pop();
            int temp = num - (floor)(num / 2.0);
            pq.push(temp);
            k--;
        }

        int sum = 0;
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};