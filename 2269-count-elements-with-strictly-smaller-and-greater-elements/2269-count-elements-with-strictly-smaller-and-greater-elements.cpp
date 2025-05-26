class Solution {
public:
    int countElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int i=0;
        int j=n-1;

        while(i+1<n && nums[i] == nums[i+1]){
            i++;
        }

        while(j-1>0 && nums[j] == nums[j-1]){
            j--;
        }
        
        int cnt = (j - i) - 1;
        return cnt > 0 ? cnt : 0;
    }
};