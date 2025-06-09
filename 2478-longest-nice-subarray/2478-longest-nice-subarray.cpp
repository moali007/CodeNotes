class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();

        int i=0;
        int j=0;

        int mask = 0;
        int maxLen = 0;
        while(j < n){
            while((nums[j] & mask) != 0){ //keep shrinking
                mask = (mask ^ nums[i]); //removing ith element from mask
                i++;
            }

            maxLen = max(maxLen, j-i+1);
            mask = (mask | nums[j]); //adding jth element to mask

            j++;
        }

        return maxLen;
    }
};