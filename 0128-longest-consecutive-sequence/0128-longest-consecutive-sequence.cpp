class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if(n==0) return 0;

        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());

        int cnt = 0;
        int maxi = 0;

        int prev = pq.top(); pq.pop();

        while(!pq.empty()){
            int curr = pq.top(); pq.pop();

            if(curr == prev) continue;

            if(curr == prev + 1){
                cnt++;
                maxi = max(maxi, cnt);
            }else{
                cnt = 0;
            }

            prev = curr;
        }

        return maxi+1;
    }
};