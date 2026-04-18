class Solution {
public:
    class compare {
        public:
        bool operator()(const string &s1, const string &s2) {
            // if lengths differ
            if (s1.length() != s2.length()) {
                return s1.length() > s2.length(); 
            }

            // if same length → lexicographically compare
            return s1 > s2;
        }
    };

    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size();

        priority_queue<string, vector<string>, compare> pq;

        for(int i = 0; i < n; i++){
            pq.push(nums[i]);

            if(pq.size() > k){
                pq.pop();
            }
        }

        return pq.top();
    }
};