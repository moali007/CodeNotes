class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        
        vector<int> result;

        for(int j = 0 ; j < n ; j++){
            if(nums[j] == key){
                int start = max(0, j-k);
                int end = min(n-1, j+k);

                if(!result.empty() && result.back() >= start){
                    start = result.back() + 1;
                }

                for(int i = start ; i <= end ; i++){
                    result.push_back(i);
                }
            }
        }

        return result;
    }
};