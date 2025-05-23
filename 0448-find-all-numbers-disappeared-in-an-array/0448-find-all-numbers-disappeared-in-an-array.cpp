class Solution {
public:
//Jab bhi de rakha ho ki nums lies in range [1,n] mtlb question is telling ki treat 
//number as index

    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            int num = abs(nums[i]);
            int idx = num - 1;

            if(nums[idx] > 0){ //not visited, go and visit
                nums[idx] *= -1;
            }

        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[i] > 0){
                ans.push_back(i+1);
            }
        }

        return ans;
    }
};