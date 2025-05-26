class Solution {
public:
    int countElements(vector<int>& nums) {
        int n = nums.size();
        
        int maxElement = *max_element(nums.begin(), nums.end());
        int minElement = *min_element(nums.begin(), nums.end());

        int cnt = 0;
        for(int i=0;i<n;i++){
            if(nums[i] > minElement && nums[i] < maxElement) cnt++;
        }

        return cnt;
    }
};