class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int median = 0;
        int mid = n / 2;
        if(n % 2 == 1){
            median = nums[mid];
        }else{
            median = (nums[mid] + nums[mid-1]) / 2;
        }

        cout<<"Median = "<<median<<endl;

        int cnt = 0;
        for(auto num : nums){
            cnt += abs(num - median) / 1;
        }
        
        return cnt;
    }
};

// 1 2 3 4 5 6 