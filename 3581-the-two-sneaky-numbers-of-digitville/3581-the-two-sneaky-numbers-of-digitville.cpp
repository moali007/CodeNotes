class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;
        vector<int> vis(n, 0);
        for(int i=0;i<n;i++){
            int num = nums[i];
            int idx = num;

            if(vis[idx] == -1){ //already visited
                ans.push_back(num);
            }
            else{
                vis[idx] = -1;
            }
        }

        return ans;
    }
};