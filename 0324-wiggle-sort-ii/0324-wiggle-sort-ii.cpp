class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> ans(n);

        int i = n-1;
        int j = 1;

        while(j < n){
            ans[j] = nums[i];
            i--;
            j += 2;
        }

        j = 0;
        while(j < n){
            ans[j] = nums[i];
            i--;
            j += 2;
        }

        for(int i=0;i<n;i++){
            nums[i] = ans[i];
        }
        

    }
};