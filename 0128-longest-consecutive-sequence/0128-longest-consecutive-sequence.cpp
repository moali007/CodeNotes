class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());

        int prev = pq.top(); pq.pop();
        int len = 0;
        int maxlen = -1e9;

        while(!pq.empty()){
            int curr = pq.top(); pq.pop();

            if(curr == prev) continue;
            if(curr == prev + 1){
                len++;
            }
            else{
                maxlen = max(maxlen, len);
                len = 0;
            }
            prev = curr;
        }
        maxlen = max(maxlen, len);

        return maxlen + 1;
    }
};