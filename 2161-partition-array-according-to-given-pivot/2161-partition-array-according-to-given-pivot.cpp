class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        int pc = 0;
        vector<int> smaller;
        vector<int> greater;

        for(int i = 0; i < n; i++){
            if(nums[i] < pivot){
                smaller.push_back(nums[i]);
            }else if(nums[i] > pivot){
                greater.push_back(nums[i]);
            }else{
                pc++;
            }
        }

        vector<int> ans;
        for(int i = 0; i < smaller.size(); i++){
            ans.push_back(smaller[i]);
        }
        while(pc--){
            ans.push_back(pivot);
        }
        for(int i = 0; i < greater.size(); i++){
            ans.push_back(greater[i]);
        }

        return ans;
    }
};