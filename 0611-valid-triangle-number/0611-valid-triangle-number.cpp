class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int index = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                index++; // Increment index for each zero
            } else {
                break; // Stop once a non-zero element is encountered
            }
        }

        int cnt = 0;
        for(int i=index;i<n;i++){
            for(int j=i+1;j<n-1;j++){
               

                int idx = lower_bound(nums.begin(), nums.end(), nums[i]+nums[j]) - (nums.begin() + j);

                cnt += idx-1;
            }
        }

        return cnt > 0 ? cnt : 0;
        
    }
};