class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        
        vector<int> ans;

        for(int j = 0 ; j < n ; j++){
            if(nums[j] == key){
                int start = max(0, j-k);
                int end = min(n-1, j+k);

                if(!ans.empty() && ans.back() >= start){
                    start = ans.back() + 1;
                }

                for(int x = start ; x <= end ; x++){
                    ans.push_back(x);
                }
            }
        }

        return ans;
    }
};