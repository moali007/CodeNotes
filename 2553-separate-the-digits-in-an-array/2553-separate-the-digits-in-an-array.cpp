class Solution {
public:
    
    void solve(int num, vector<int> &ans){
        vector<int> v;
        while(num > 0){
            int d = num % 10;
            v.push_back(d);
            num = num / 10;
        }

        for(int i = v.size() - 1; i >=0; i--){
            ans.push_back(v[i]);
        }
    }

    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;

        for(int i = 0; i < n; i++){
            int num = nums[i];

            solve(num, ans);
        }

        return ans;
    }
};