class Solution {
    //codestorywithmik - jab bhi hame de rakha hai ki array elements are in range of [1,n]
    //this means, question hame bata ra ki use numbers as indexes
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;
        for(int i=0;i<n;i++){
            int num = abs(nums[i]);
            int idx = num - 1;

            if(nums[idx] < 0){ // already visited, mtlb num appears twice
                ans.push_back(num);
            }
            else nums[idx] *= -1;  //visit it
        }

        return ans;
    }
};