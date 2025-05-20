class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<int> diffArr(n, 0);

        for(auto q : queries) {
            int start = q[0];
            int end = q[1];

            diffArr[start] += 1;
            if(end + 1 < n){
                diffArr[end+1] -= 1;
            }
        }

        //taking cummulative sum in diffArr
        for(int i=1;i<n;i++){
            diffArr[i] += diffArr[i-1];
        }

        for(int i=0;i<n;i++){
            if(nums[i] - diffArr[i] > 0) return false;
        }

        return true;
    }
};